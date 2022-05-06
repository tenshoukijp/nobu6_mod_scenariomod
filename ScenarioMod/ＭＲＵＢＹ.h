#ifdef USE_MRUBY_INTERPRETER

#pragma once

#pragma pack(1)

#include <string>
#include "mruby/�l�q�t�a�x�qinterface�r.h"

using namespace std;




namespace �֐� {
	namespace MRUBY {

		/// <summary>
		/// MRUBY�̗�O�^�B
		/// </summary>
		class ��O�^ : public std::exception {
		public:
			��O�^(std::string cause) : std::exception(cause.c_str()) {}
		};


		/// <summary>
		/// MRUBY�̎w��̃O���[�o�X�ϐ��̒��g���u����(����)�v�Ƃ݂Ȃ��āA�擾�B
		/// <para>�Ԃ�l�F�ϐ��̒��g������(����)�Ƃ݂Ȃ��Ď擾����B</para>
		/// <para>�擾�Ɏ��s�����ꍇ�A�uMRUBY::��O�^�v�̗�O����������B</para>
		/// </summary>
		/// <param name="�ϐ���">���g���擾�������O���[�o���ϐ���</param>
		/// <returns>�ϐ��̒��g�ł������</returns>
		double Get_�O���[�o�����l(string �ϐ���);


		/// <summary>
		/// MRUBY�̑Ώۂ̃O���[�o�X�ϐ��̒��g���u������v�Ƃ݂Ȃ��āA�擾�B
		/// <para>�Ԃ�l�F�ϐ��̒��g�𕶎���Ƃ݂Ȃ��Ď擾����B</para>
		/// <para>�擾�Ɏ��s�����ꍇ�A�uMRUBY::��O�^�v�̗�O����������B</para>
		/// </summary>
		/// <param name="�ϐ���">���g���擾�������O���[�o���ϐ���</param>
		/// <returns>�ϐ��̒��g�ł��镶����</returns>
		string Get_�O���[�o��������(string �ϐ���);


		/// <summary>
		/// MRUBY�̃X�e�[�g(�R�[�h)�����s����B
		/// <para>�Ԃ�l�F�����G���[���Ȃ���΁A�O���Ԃ��Ă���B</para>
		/// <para>�G���[������΁A�uMRUBY::��O�^�v�̗�O����������B</para>
		/// </summary>
		/// <param name="�R�}���h������">���s������MRUBY�̃X�e�[�g(�R�[�h�A���ߕ�)</param>
		/// <returns>�����G���[���Ȃ���΁A�O���Ԃ��Ă���B<para>�G���[������΁A�uMRUBY::��O�^�v�̗�O����������B</para></returns>
		int Do_�R�}���h(string �R�}���h������);


		/// <summary>
		/// �w���MRUBY�̃t�@�C����MRUBY���߂��Ď��s����B
		/// <para>�Ԃ�l�F�����G���[���Ȃ���΁A�O���Ԃ��Ă���B</para>
		/// <para>�G���[������΁A�uMRUBY::��O�^�v�̗�O����������B</para>
		/// </summary>
		/// <param name="�t�@�C����">���s������MRUBY�̃t�@�C����</param>
		/// <returns>�����G���[���Ȃ���΁A�O���Ԃ��Ă���B<para>�G���[������΁A�uMRUBY::��O�^�v�̗�O����������B</para></returns>
		int Do_�t�@�C��(string �t�@�C����);
	}

	ostream& operator<<(ostream& os, �֐�::MRUBY::��O�^& e);
}




#endif