// fun.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int enum_files_in_dir(const char *pdir, list<string> *plist) {

	int ifind_err = 1;
	char dir_temp[1024];
	sprintf_s(dir_temp, 1024, "%s*.*", pdir);

	struct _finddata_t fi;
	intptr_t ptr = _findfirst(dir_temp, &fi);
	if (-1 == ptr) {
		printf("_findfirst error");
		return ifind_err;
	} else {
		while (true)
		{
			if (!(fi.attrib & _A_SUBDIR))
			{
				plist->push_back(fi.name);
			}

			int ierr = _findnext(ptr, &fi);
			if (-1 == ierr)
			{
				if (ENOENT == errno)
				{
					ifind_err = 0;
				}
				break;
			}
		}
		_findclose(ptr);
		
	}

	return ifind_err;
}

int convert_avi_to_mp4(const char *bin_ffmpeg, const char *pdir_avi, const char *pdir_mp4) {
	list<string> files;
	int ierr = enum_files_in_dir(pdir_avi, &files);
	if (0 == ierr)
	{
		list<string>::iterator it;
		for (it  = files.begin(); it != files.end(); it++)
		{
			char cmd[1024];
			sprintf_s(cmd, 1024, "%s -i \"%s%s\" \"%s%s.mp4\"", bin_ffmpeg, pdir_avi, (*it).c_str(), pdir_mp4, (*it).c_str());			
			//printf_s("%s\n", cmd);
			system(cmd);
		}
	}

	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	if (4 != argc)
	{
		printf_s("usage: fun bin_ffmpeg dir_avi dir_mp4");
		return 0;
	}
//	convert_avi_to_mp4("dd", "C:\\Users\\meng\\Documents\\地下城与勇士\\video\\*.*", "d:", );
	convert_avi_to_mp4(argv[1], argv[2], argv[3]);

	return 0;
}

