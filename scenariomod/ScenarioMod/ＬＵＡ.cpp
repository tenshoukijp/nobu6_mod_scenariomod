#include <string>

#include "�Q�[���f�[�^�\��.h"

using namespace std;

namespace �֐� {
	namespace LUA {
		double Get_�O���[�o�����l(string �ϐ���) {
			try {
				double ret = lua_getglobal_numtype((char *)�ϐ���.c_str());
				return ret;
			} catch (...) {
				throw LUA::��O�^("LUA::Get_�O���[�o�����l�G���[");
			}
		}

		string Get_�O���[�o��������(string �ϐ���) {
			try {
				string ret = lua_getglobal_strtype((char *)�ϐ���.c_str());
				return ret;
			} catch (...) {
				throw LUA::��O�^("LUA::Get_�O���[�o��������G���[");
			}
		}


		int Do_�R�}���h(string �R�}���h������) {
			int ret = lua_DoStringFormat(�R�}���h������.c_str());
			if (ret) {
				throw LUA::��O�^("LUA::Do_�R�}���h�G���[");
			} else {
				return ret;
			}
		}

		int Do_�t�@�C��(string �t�@�C����) {
			string �R�}���h������ = "dofile('"+�t�@�C����+"')";
			int ret = lua_DoStringFormat(�R�}���h������.c_str());
			if (ret) {
				throw LUA::��O�^("LUA::Do_�t�@�C���G���[");
			} else {
				return ret;
			}
		}

	}

	ostream& operator<<(ostream& os, �֐�::LUA::��O�^& e)
	{
		os << e.what();
		return os;
	}
}


