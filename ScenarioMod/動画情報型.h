/*
 * ������A�����郀�[�r�[�֘A
 */
#pragma once
#pragma pack(1)

#include <windows.h>

#include "�������.h"

namespace �֐� {

	/// <summary>
	/// �w��̓�����Đ�����B
	/// <examples>
	/// <para>
	/// <code>
	/// ����Đ�("KOEILOGO"); // movie�t�H���_�ɂ���koeilogo.avi �t�@�C���𕁒ʂ̓���Ɠ��l�ɍĐ�
	/// </code>
	/// </para>
	/// <para>
	/// <code>
	/// ����Đ�("HOGEHOGE", ����::���w�i�n�e�e | ����::�a�f�l�p��); // movie�t�H���_�ɂ���hogehoge.avi�t�@�C�����A�w�i���ɂ����ABGM���p�������܍Đ�����B
	/// </code>
	/// </para>
	/// <para>
	/// <code>
	/// ����Đ�("SN_MY.+"); // ���̂悤�ɐ��K�\���Ŏw�肷��ƁA���̏����𖞂������̂�����P��I�����čĐ�����B ���������̂��P�������ƁA�b�c�|�q�n�l�̑}�������߂���̂Œ��ӁB
	/// </code>
	/// </para>
	/// </examples>
	/// </summary>
	/// <param name="���於">�Ώۂ̓���t�@�C���̖��O�B�umovie\(���於).avi�v�Ƃ����t�@�C����T���ɂ����B</param>
	/// <param name="�I�v�V����">�u����::���w�i�n�m�`����::�a�f�l�p���v ���u|�v�őg�ݍ��킹�ė��p����B
	/// <para>�f�t�H���g�l�́u�I�v�V����= ����::���w�i�n�m|����::�a�f�l��~�v</para>
	/// </param>
	void ����Đ�(string ���於, int �I�v�V����= ����::���w�i�n�m|����::�a�f�l��~);

}


