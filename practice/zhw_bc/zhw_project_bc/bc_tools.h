
#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <wchar.h>
#include <windows.h>


class CBcTools
{
public:
    static void UTF8ToUnicode(char *cUTF8, wchar_t wcUnicode[]);
    static const char * UTF8ToChar(const char *cUTF8);
    static char * replace_char(char *pstr, char srcchar, char dstchar);
    static int dcf_file_replace_content(const char *src_file, const char *dst_file, const char *src_content, const char *dst_content);
    static HRESULT CallJSFunction(IHTMLDocument2* pDoc2,CString strFunctionName,DISPPARAMS dispParams,VARIANT* varResult,EXCEPINFO* exceptInfo,UINT* nArgErr);
};
