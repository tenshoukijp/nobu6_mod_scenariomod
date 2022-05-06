#pragma once
#pragma pack(1)

#include <windows.h>
#include "�f�o�b�O�N���X.h"

namespace �֐� {

	/// <summary>
	/// �f�o�b�O�o�̓X�g���[���B
	/// C�����printf�֐����A�������́AC++�����cout���̋L�q���\�B
	/// <examples>
	/// <para>�@ printf(format, ...);  �ɂ�������ȋL�@</para>
	/// <para>
	/// <code>
	/// �f�o�b�O�o��( "%s", �����b�Z�[�W.c_str() );
	/// </code>
	/// </para>
	/// <para>�A cout &lt;&lt; ... &lt;&lt; endl;  �ɂ�������ȋL�@</para>
	/// <para>
	/// <code>
	/// �f�o�b�O�o�� &lt;&lt; ������ &lt;&lt; ":" &lt;&lt; �����b�Z�[�W &lt;&lt; (int)���b�Z�[�W�֘A���.��P�l�́y�����ԍ��z &lt;&lt; endl;
	/// <para>(endl �������́A�f�o�b�O�o��.flush() �����i�K�ŏo�͂����B)</para>
	/// </code>
	/// </para>
	/// </examples>
	/// </summary>
	extern �f�o�b�O�X�g���[���^ �f�o�b�O�o��;

	/// <summary>
	/// System::String^ �^���f�o�b�O�o�͂ɑΉ�������B
	/// </summary>
	extern �f�o�b�O�X�g���[���^& operator << (�f�o�b�O�X�g���[���^& os, System::String^ str);

}

