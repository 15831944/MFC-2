
#include "bc_tools.h"
#include "io.h"
#define MAX_STR_LEN 512
//��UTF-8����ת��ΪUnicode����  
void CBcTools::UTF8ToUnicode(char *cUTF8, wchar_t wcUnicode[])
{
    std::string sUTF8 = cUTF8;
    int nLen = MultiByteToWideChar(CP_UTF8, 0, sUTF8.c_str(), -1, NULL, 0);
    MultiByteToWideChar(CP_UTF8, 0, sUTF8.c_str(), -1, (LPWSTR)wcUnicode, nLen);
}

/****************************************************************
*�������� : �����Ǵ��д���ģ�����ʼ��ֻ��һ�����棬�������ʹ�þ�̬�ڴ棬����Ƶ�������ͷ��ڴ�
*������� : NA
*������� : NA
*���ز��� : NA
*��   �� :     zjb
*�������� : 2017-08-22  8:57:14
****************************************************************/
const char * CBcTools::UTF8ToChar(const char *cUTF8)
{
    static wchar_t wcstr[MAX_STR_LEN];
    static char asin[MAX_STR_LEN/2];
    int convresult_w = ::MultiByteToWideChar(CP_UTF8, 0, cUTF8,-1,wcstr,MAX_STR_LEN);
    int convresult_c =::WideCharToMultiByte(CP_OEMCP, 0, wcstr, -1, asin, MAX_STR_LEN/2, NULL, NULL);
    return asin;
}


int CBcTools::dcf_file_replace_content(const char *src_file, const char *dst_file, const char *src_content, const char *dst_content)
{
    #define FILE_BUF_LEN 1*1024
    BYTE buffer[FILE_BUF_LEN];
    int read_len;
    DWORD dwRet = -1;
    BYTE *w_begin = NULL;
    BYTE *r_begin = NULL;
    BYTE *r_cur = NULL;

    size_t ileft_len;
    size_t itotal_len;
    if ((!src_file) || (!dst_file) || (!src_content) || (!dst_content) || (!(*src_content)))
    {
        return -100;
    }

    size_t ilen_src = strlen(src_content);
    size_t ilen_dst = strlen(dst_content);
    size_t iPt_cur = 0;
    size_t len_w = 0;
    FILE *srcfile = NULL;
    errno_t  err = fopen_s(&srcfile,src_file, "rb");
    if (srcfile == NULL)
    {
        return -1;
    }

    FILE *dstfile = NULL;
    dstfile = fopen(dst_file, "w");
    if (!dstfile)
    {        
        goto cleanup;
    }

    if (fseek(srcfile, 0, SEEK_SET) != 0)
    {
        goto cleanup;
    }

    r_begin = buffer;
    ileft_len = 0;
    for (;;)
    {
        read_len = (DWORD)fread(buffer + ileft_len, 1, FILE_BUF_LEN - ileft_len, srcfile);
        if (ferror(srcfile))
        {
            goto cleanup;
        }

        if (read_len <= 0)
        {
            break;
        }

        w_begin = buffer;
        r_cur = buffer;
        itotal_len = read_len + ileft_len;
        // ��ƥ���ַ�
        iPt_cur = 0;
        for (; iPt_cur < itotal_len; iPt_cur++, r_cur++)
        {
            if (*r_cur == 0x0a)
            {
                // һ�н���
                len_w = ((size_t)r_cur - (size_t)w_begin) + 1;
                if (fwrite(w_begin, 1, len_w, dstfile) != len_w || ferror(dstfile))
                {
                    goto cleanup;
                }
                w_begin = r_cur + 1;
                continue;
            }

            if (*r_cur == (*(BYTE*)src_content))
            {
                if ((iPt_cur + ilen_src) > itotal_len)
                {
                    // ������
                    break;
                }

                // ����
                if (!memcmp(r_cur, src_content, ilen_src))
                {
                    // ��ͬ
                    // �Ȱ�ǰ��д��,����ǰ��Ҫд��ĳ���
                    len_w = ((size_t)r_cur - (size_t)w_begin);
                    if (len_w && (fwrite(w_begin, 1, len_w, dstfile) != len_w || ferror(dstfile)))
                    {
                        goto cleanup;
                    }

                    // �ٰ�����ַ�д��
                    if (ilen_dst)
                    {
                        if (fwrite(dst_content, 1, ilen_dst, dstfile) != ilen_dst || ferror(dstfile))
                        {
                            goto cleanup;
                        }
                    }

                    // �����´�д���λ��
                    w_begin = (r_cur + ilen_src);
                    // ��Ϊ�����ⲿѭ�����++������Ҫ��һ
                    r_cur += (ilen_src - 1);
                    iPt_cur += (ilen_src - 1);
                }// ��⵽����ַ�
            }// �ҵ���һ���ַ���ͬ
             // ������һ���ַ�
        }// ���ζ������ݴ�����
         // �������֮�󣬿��ܻ���ʣ��ģ��������ж�
        len_w = ((size_t)w_begin - (size_t)buffer);
        ileft_len = 0;
        if (len_w < itotal_len)
        {
            // ����ʣ���
            ileft_len = itotal_len - len_w;
            memmove(buffer, w_begin, ileft_len);
        }
    }

    if (ileft_len)
    {
        // ����ʣ���
        if (fwrite(buffer, 1, ileft_len, dstfile) != ileft_len || ferror(dstfile))
        {
            goto cleanup;
        }
    }

    dwRet = 0;
cleanup:
    if (srcfile)
    {
        fclose(srcfile);
    }

    if (dstfile)
    {
        fclose(dstfile);
    }

    return dwRet;
}

char * CBcTools::replace_char(char *pstr, char srcchar, char dstchar)
{
    char *pcur = pstr;
    while (*pcur)
    {
        if (*pcur == srcchar) *pcur = dstchar;
        pcur++;
    }
    return pstr;
}

HRESULT CBcTools::CallJSFunction(IHTMLDocument2* pDoc2,
    CString strFunctionName,
    DISPPARAMS dispParams,
    VARIANT* varResult,
    EXCEPINFO* exceptInfo,
    UINT* nArgErr)
{
    IDispatch *pDispScript = NULL;
    HRESULT hResult;
    hResult = pDoc2->get_Script(&pDispScript);
    if (FAILED(hResult))
    {
        return S_FALSE;
    }

    DISPID   dispid;
    CComBSTR objbstrValue = strFunctionName;
    BSTR bstrValue = objbstrValue.Copy();
    OLECHAR *pszFunct = bstrValue;
    hResult = pDispScript->GetIDsOfNames(IID_NULL,
        &pszFunct,
        1,
        LOCALE_SYSTEM_DEFAULT,
        &dispid);
    if (FAILED(hResult))
    {
        pDispScript->Release();
        return hResult;
    }

    varResult->vt = VT_VARIANT;
    hResult = pDispScript->Invoke(dispid,
        IID_NULL, LOCALE_USER_DEFAULT,
        DISPATCH_METHOD,
        &dispParams,
        varResult,
        exceptInfo,
        nArgErr);
    pDispScript->Release();

    return hResult;
}