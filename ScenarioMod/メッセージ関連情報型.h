/*
 * ���o���Ȃǂɂ�����A���́E�q�́E��R�ҁv��ID
 */
#pragma once
#pragma pack(1)

#include <windows.h>
#include <string>
#include <vector>
#include <map>

using namespace std;


using �����񃊃X�g�^ = vector<string>;

// --------------------------------------���b�Z�[�W�֘A���
struct ���b�Z�[�W�֘A���^ {
	WORD ��P�l�́y�����ԍ��z;	// ������ID(�ʏ핐��ID)
	WORD ��Q�l�́y�����ԍ��z;	// �����ID(�ʏ핐��ID�B�C�x���g��⏤�l���531,�_�����532�ƂȂ�)
	WORD ��R�l�́y�����ԍ��z;	// ��R�҂�ID(�ʏ�1stPerson��2ndPerson�̉�b�̒��ŏo�Ă���l��ID);

	// -----------�ȉ��\���B�����̊g���ɑ΂���݊����m�ۂ̂��߁B
	DWORD _undef1;
	DWORD _undef2;
	DWORD _undef3;
	DWORD _undef4;
	DWORD _undef5;
};





// --------------------------------------�����񔻒�̂��߂̐��K�\���֐�

namespace �֐� {

	// �Ώە�����ɁA���������񂪊܂܂�Ă��邩�ǂ����̔���
	BOOL Is_������}�b�`( string �Ώە�����, string ����������);



	/// <summary>
	/// �uIs_���K�\���}�b�`�v�̊֐��ŁA�L���v�`���[���󂯎�邽�߂̌^�B
	/// </summary>
	using ���K�\���}�b�`���ʌ^ = map<int, string>;

	/// <summary>
	/// ���K�\������p�̊֐��B
	/// <examples>
	/// <para>-------------------------------------------------
	/// <para>�g�����̗�@: �ȒP�Ȑ��K�\���̗�</para>
	/// <code>
	/// <para>�@ �@</para>
	/// <para>if ( Is_���K�\���}�b�`(�����b�Z�[�W, &quot;�Ă�.+?�ق�\x0A��&quot;) ) {</para>
	/// <para>   ....</para>
	/// <para>}</para>
	/// </code>
	/// </para>
	/// <para>-------------------------------------------------
	/// <para>�g�����̗�A: �ڍ׌���(�L���v�`������)�����߂�ꍇ</para>
	/// <code>
	/// <para>�@ �@</para>
	/// <para>���K�\���}�b�`���ʌ^ �}�b�`����;</para>
	/// <para>if ( Is_���K�\���}�b�`(�����b�Z�[�W, &quot;�Ă�(.+?)�ق�&quot;, &amp;�}�b�`���� ) ) {</para>
	/// <para>   ....</para>
	/// <para>}</para>
	///	<para>�f�o�b�O�o�� &lt;&lt; �}�b�`����[0] &lt;&lt; &quot;:&quot; &lt;&lt; �}�b�`����[1] &lt;&lt; endl;</para>
	/// </code>
	/// <para>�@ �@</para>
	/// <para>�}�b�`����[1]�̂悤�ɔԍ��ŃA�N�Z�X����B���g�͕�����B</para>
	/// <para>�O�Ԗڂ��}�b�`���������̕�����S��</para>
    /// <para>�P�Ԗڈȍ~���i�@�j�ł������������Ƀ}�b�`���������񂪏����i�[�����B</para>
	/// <para>���݂��Ȃ��ԍ��̕�����ɃA�N�Z�X�����ꍇ�́A��̕����񑊓��ł���""����Ԃ��Ă���B</para>
	/// </para>
	/// <para>-------------------------------------------------
	/// <para>�g�����̗�B: ���^�L�����N�^�[���g�p�\</para>
	/// <code>
	/// <para>�@ �@</para>
	/// <para>if ( Is_���K�\���}�b�`(�����b�Z�[�W, &quot;^��.+[�Ĕn�S�C]+��[0-9]+�ق�\\s��&quot; ) ) { </para>
	/// <para>   ....</para>
	/// <para>}</para>
	/// </code>
	/// <para>�@ �@</para>
	/// <para>�ȏ�̂悤�ɢ^���\\d��A�\\s��Ȃǂ����p�\���B�G�X�P�[�v�ɒ��ӂ���K�v������B</para>
	/// </para>
	/// </examples>
	/// </summary>
	/// <param name="�Ώە�����">�Ώۂ̌��̕�����</param>
	/// <param name="���K�\��������">���K�\����������������B</param>
	/// <param name="���K�\���}�b�`����">���K�\���}�b�`���ʌ^�̕ϐ��̃|�C���^��n���B(.+?)���ɂ��L���v�`�����ʂ��󂯎�邽�߂̂��́B</param>
	/// <return>���K�\�����ʂ��^�Ȃ�TRUE�A�U�Ȃ�FALSE</return>
	BOOL Is_���K�\���}�b�`(string �Ώە�����, string ���K�\��������, ���K�\���}�b�`���ʌ^* ���K�\���}�b�`���� = NULL);
}

