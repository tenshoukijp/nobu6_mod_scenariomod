/*
 * �R�}���h�����
 */
#pragma once
#pragma pack(1)

#include <windows.h>
#include <string>

#include "�R�}���h����.h"

using namespace std;




namespace �֐� {
	/// <summary>
	/// ���ꂼ��̃R�}���h�̍s���͂�ݒ肷��B
	/// <para>�����ł����s���͂Ƃ́A����̃R�}���h�����s�����ۂɏ����s���͂̏���l�̂��Ƃł���B</para>
	/// </summary>
	/// <param name="�s���̓R�}���h��">�Ώۂ̃R�}���h�̃^�C�v
	/// <para>�u���C�����::�s���̓R�}���h��::�u�`�v�`�u���C�����::�s���̓R�}���h��::�����E�P���E���i�v�ɑΉ����Ă���B</para>
	/// </param>
	/// <param name="�s����">�R�}���h�����s�����ۂɏ����u�s���͂̏���l�v�̂��ƁB</param>
	void Set_�R�}���h�s����(int �s���̓R�}���h��, int �s����);
}








namespace �֐� {


	/// <summary>
	/// ����ɕ\�������R�}���h���̕������ύX����B
	/// <para>���̊֐��́u�ȉ��̂Q�̃��\�b�h�̒��ł̂݁v�g���邱�Ƃ�O��Ƃ��Ă���B</para>
	/// <para>
	/// <code>
	///      On_�퓬�R�}���h�\�����O�s�푈��ʁt(int �����ԍ�);
	/// </code>
	/// </para>
	/// <para>
	/// <code>
	///      On_��{�R�}���h�\�����O�s�푈��ʁt(int �����ԍ�);
	/// </code>
	/// </para>
	/// <para>���̃��\�b�h���ŗ��p���ꂽ�ꍇ�̋����͖���ł���B</para>
	/// <examples>
	/// <para>��:
	/// <code>
	///      Set_�R�}���h��( �푈���::�퓬�R�}���h��::�ʏ�U��, "���΂�");
	/// </code>
	/// </para>
	/// </examples>
	/// </summary>
	/// <param name="�R�}���h���h�c">�ύX����R�}���h���̃V���{��ID�B
	/// <para>�u�푈���::�퓬�R�}���h��::�ʏ�U���v�`�u�푈���::�퓬�R�}���h��::��C�U���v�������́A</para>
	/// <para>�u�푈���::��{�R�}���h��::�ە��v�`�u�푈���::��{�R�}���h��::�ꊅ�v�ɑΉ�����B</para>
	/// </param>
	/// <param name="�V�R�}���h�̕�����">�Ώۂ̃R�}���h���ɑւ��ĕ\������V����������</param>
	void Set_�R�}���h��(int �R�}���h���h�c, string �V�R�}���h�̕�����);


	/// <summary>
	/// �푈���A���蕐���ɑ΂��đދp�R�}���h���v���O���������甭���ł���B
	/// <para>���̊֐��́u�ȉ��̂Q�̃��\�b�h�̒��ł̂݁v�g���邱�Ƃ�O��Ƃ��Ă���B</para>
	/// <para>
	/// <code>
	///     On_�^�[���ύX�s�U�钆��ʁt(int �^�[����);
	/// </code>
	/// </para>
	/// <para>
	/// <code>
	///      On_�c��^�[���ύX�s�푈��ʁt(int �c��^�[����);;
	/// </code>
	/// </para>
	/// <para>���̃��\�b�h���ŗ��p���ꂽ�ꍇ�̋����͖���ł���B</para>
	/// </summary>
	/// <param name="�����ԍ��y�z��p�z">�ΏۂƂȂ镐���́u�z��p�v�̔ԍ�</param>
	int Do_�R�}���h�s�푈��ʁt�s�ދp�t(int �����ԍ��y�z��p�z);
}




