#pragma once

#pragma pack(1)

#include <string>
#include "lua/�k�t�`�qinterface�r.h"

using namespace std;




namespace �֐� {
	namespace LUA {

		/// <summary>
		/// LUA�̗�O�^�B
		/// </summary>
		class ��O�^ : public std::exception {
		public:
			��O�^(std::string cause) : std::exception(cause.c_str()) {}
		};


		/// <summary>
		/// LUA�̎w��̃O���[�o�X�ϐ��̒��g���u����(����)�v�Ƃ݂Ȃ��āA�擾�B
		/// <para>�Ԃ�l�F�ϐ��̒��g������(����)�Ƃ݂Ȃ��Ď擾����B</para>
		/// <para>�擾�Ɏ��s�����ꍇ�A�uLUA::��O�^�v�̗�O����������B</para>
		/// </summary>
		/// <param name="�ϐ���">���g���擾�������O���[�o���ϐ���</param>
		/// <returns>�ϐ��̒��g�ł������</returns>
		double Get_�O���[�o�����l(string �ϐ���);


		/// <summary>
		/// LUA�̑Ώۂ̃O���[�o�X�ϐ��̒��g���u������v�Ƃ݂Ȃ��āA�擾�B
		/// <para>�Ԃ�l�F�ϐ��̒��g�𕶎���Ƃ݂Ȃ��Ď擾����B</para>
		/// <para>�擾�Ɏ��s�����ꍇ�A�uLUA::��O�^�v�̗�O����������B</para>
		/// </summary>
		/// <param name="�ϐ���">���g���擾�������O���[�o���ϐ���</param>
		/// <returns>�ϐ��̒��g�ł��镶����</returns>
		string Get_�O���[�o��������(string �ϐ���);


		/// <summary>
		/// LUA�̃X�e�[�g(�R�[�h)�����s����B
		/// <para>�Ԃ�l�F�����G���[���Ȃ���΁A�O���Ԃ��Ă���B</para>
		/// <para>�G���[������΁A�uLUA::��O�^�v�̗�O����������B</para>
		/// </summary>
		/// <param name="�R�}���h������">���s������LUA�̃X�e�[�g(�R�[�h�A���ߕ�)</param>
		/// <returns>�����G���[���Ȃ���΁A�O���Ԃ��Ă���B<para>�G���[������΁A�uLUA::��O�^�v�̗�O����������B</para></returns>
		int Do_�R�}���h(string �R�}���h������);


		/// <summary>
		/// �w���LUA�̃t�@�C����LUA���߂��Ď��s����B
		/// <para>�Ԃ�l�F�����G���[���Ȃ���΁A�O���Ԃ��Ă���B</para>
		/// <para>�G���[������΁A�uLUA::��O�^�v�̗�O����������B</para>
		/// </summary>
		/// <param name="�t�@�C����">���s������LUA�̃t�@�C����</param>
		/// <returns>�����G���[���Ȃ���΁A�O���Ԃ��Ă���B<para>�G���[������΁A�uLUA::��O�^�v�̗�O����������B</para></returns>
		int Do_�t�@�C��(string �t�@�C����);
	}

	ostream& operator<<(ostream& os, �֐�::LUA::��O�^& e);
}


