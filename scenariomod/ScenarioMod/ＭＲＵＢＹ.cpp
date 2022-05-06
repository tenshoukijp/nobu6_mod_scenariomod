#ifdef USE_MRUBY_INTERPRETER


#include <string>
#include "mruby/�l�q�t�a�x�qinterface�r.h"

#include "�Q�[���f�[�^�\��.h"

using namespace std;

namespace �֐� {
	namespace MRUBY {

		double Get_�O���[�o�����l(string �ϐ���) {
			try {
				double ret = mruby_getglobal_numtype(mrb, (char *)�ϐ���.c_str());
				return ret;
			}
			catch (...) {
				throw MRUBY::��O�^("MRUBY::Get_�O���[�o�����l�G���[");
			}
		}

		string Get_�O���[�o��������(string �ϐ���) {
			try {
				string ret = mruby_getglobal_strtype(mrb, (char *)�ϐ���.c_str());
				return ret;
			}
			catch (...) {
				throw MRUBY::��O�^("MRUBY::Get_�O���[�o��������G���[");
			}
		}


		int Do_�R�}���h(string �R�}���h������) {
			try {
				mruby_dostring(mrb, �R�}���h������.c_str());
				return 0;
			}
			catch (...) {
				throw MRUBY::��O�^("MRUBY::Do_�R�}���h�G���[");
			}
		}

		int Do_�t�@�C��(string �t�@�C����) {
			try {
				mruby_dofile(mrb, �t�@�C����.c_str());
				return 0;
			}
			catch (...) {
				throw MRUBY::��O�^("MRUBY::Do_�t�@�C���G���[");
			}
		}
	}

	std::ostream& operator<<(std::ostream& os, �֐�::MRUBY::��O�^& e)
	{
		os << e.what();
		return os;
	}
}





#endif