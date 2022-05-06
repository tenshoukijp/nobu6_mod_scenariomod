#pragma once

/*
 �f�o�b�O�o�͂̂��߂̃e���v���[�g
 �@printf(format, ...)�ɂ�������ȋL�@

 �@�@�f�o�b�O�o��( "%s", �����b�Z�[�W.c_str() );

 �Acout << ... �ɂ�������ȋL�@

	 �f�o�b�O�o�� << ������ << ":" << �����b�Z�[�W << (int)���b�Z�[�W�֘A���.��P�l�́y�����ԍ��z << endl;

 ���̗�����f�o�b�O�o�ͣ�Ƃ����V���O���g��(�O���)�C���X�^���X�ŃT�|�[�g���邽�߂̃N���X��錾
*/


#include <istream>
#include <ostream>
#include <sstream>
#include <windows.h>
#include <tchar.h>
#include <msclr/marshal_cppstd.h>

extern BOOL _isDoingDialog;

// �C4996�v�̃��[�j���O�̔�������R�[�h�������Ă��A�R���p�C�����ɂ͏o�͂���Ȃ��Ȃ�B
#pragma warning(push)
#pragma warning(disable:4996)

// OutputDebugString�ւƃt�H�[�}�b�g(printf)�`���𗘗p���ďo�͂���B
extern char szBufOutputDebugStream[4096];


// VC++ �� STLport ���� using std::char_traits; �݂����Ȃ̂��K�v����
template <typename Ch_T, typename Tr_T = std::char_traits<Ch_T> >
class basic_dbg_streambuf: public std::basic_stringbuf<Ch_T, Tr_T> {
public:
	basic_dbg_streambuf() {
#ifndef STDX_DSTREAM_BUFFERING
		setbuf(0,0);
#endif
	}

	virtual ~basic_dbg_streambuf() {
		sync();
	}

protected:
	int sync(void) {
		dbg_out(str().c_str());
		pbump(static_cast<int>(pbase() - pptr()));
		return 0;
	}

	void dbg_out(const Ch_T*);
};

template <>
inline void basic_dbg_streambuf<char>::dbg_out(const char *str)	{
	// �_�C�A���O�\�����Ȃ牽�����Ȃ�
	if (_isDoingDialog ) {
		return;
	}

	::OutputDebugStringA(str);
}

template <>
inline void basic_dbg_streambuf<wchar_t>::dbg_out(const wchar_t *str) {
	// �_�C�A���O�\�����Ȃ牽�����Ȃ�
	if (_isDoingDialog ) {
		return;
	}

	::OutputDebugStringW(str);
}

template <typename Ch_T, typename Tr_T = std::char_traits<Ch_T> >
class basic_dbg_ostream: public std::basic_ostream<Ch_T, Tr_T> {
public:
	basic_dbg_ostream() : std::basic_ostream<Ch_T, Tr_T>(new basic_dbg_streambuf<Ch_T, Tr_T>())	{
	}

	virtual ~basic_dbg_ostream() {
		delete rdbuf();
	}

	/// <summary>
	/// �f�o�b�O�o�̓X�g���[����printf�֐��Ɠ����L�q���@�B
	/// </summary>
	void operator()( const char *format, ... ) {

		// �_�C�A���O�\�����Ȃ牽�����Ȃ�
		if (_isDoingDialog ) {
			return;
		}
		int length = sizeof(szBufOutputDebugStream) -1;


		va_list arg;

		va_start(arg, format);
		_vsnprintf_s(szBufOutputDebugStream, length, _TRUNCATE, format, arg);
		va_end(arg);

		// �Ō�̕��������s�ł͂Ȃ��ꍇ
		if ( szBufOutputDebugStream[strlen(szBufOutputDebugStream)-1] != '\n' ) {
			// ���s�𑫂��B
			strcat( szBufOutputDebugStream, "\n");
		}

		szBufOutputDebugStream[length - 1] = '\0'; // �ԕ��B�ň��̏ꍇ�͍Ō�̉��s������ׂ��B

		// OutputDebugString�̕��ɏo���B
		OutputDebugString( szBufOutputDebugStream );
	}

	void operator()(System::String^ str) {
		// �_�C�A���O�\�����Ȃ牽�����Ȃ�
		if (_isDoingDialog) {
			return;
		}
		std::string native_string = msclr::interop::marshal_as<std::string>(str);
		OutputDebugString(native_string.c_str());
	}
};





using dbg_streambuf		   = basic_dbg_streambuf<_TCHAR>;
using �f�o�b�O�X�g���[���^ = basic_dbg_ostream<_TCHAR>;

// �ȏ�uC4996�v�̃��[�j���O�̔�������R�[�h�������Ă��A�R���p�C�����ɂ͏o�͂���Ȃ��Ȃ�B
#pragma warning(pop)

