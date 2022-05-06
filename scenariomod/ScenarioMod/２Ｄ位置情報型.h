
// ���ʂ̂Q�c�x�N�g���^�B
#pragma once

#include <string>
#include "�⏕���C�u����.h"

using namespace std;



/// <summary>
/// �Q�c�ʒu�i������Position��Point�Ƃ������T�O)�̃N���X�B
/// <para>������r���Z�q�Ƃ��ẮA �u==�v�Ɓu!=�v�B</para>
/// <para>���A
/// <code>
/// �Q�c�x�N�g���^ v = p2 - p1
/// </code>
/// </para>
/// <para>�Ƃ����悤�ɁA�`�n�_����a�n�_���������ƂŁA�P�̕����x�N�g���ƂȂ�܂��B</para>
/// </summary>
struct �Q�c�ʒu�^ {

	double �w;  // �w�ʒu
	double �x;  // �x�ʒu

	/// <summary>
	/// �w�ʒu�A�x�ʒu���w�肷��R���X�g���N�^
	/// </summary>
	/// <param name="�w�ʒu">�w�ʒu</param>
	/// <param name="�x�ʒu">�x�ʒu</param>
	�Q�c�ʒu�^(double �w�ʒu, double �x�ʒu) : �w(�w�ʒu), �x(�x�ʒu) {}

	/// <summary>
	/// ���_�ʒu�̃R���X�g���N�^�B
	/// </summary>
	�Q�c�ʒu�^() : �w(0), �x(0) {}

	/// <summary>
	/// �R�s�[�R���X�g���N�^�����B
	/// </summary>
	�Q�c�ʒu�^& operator=(const �Q�c�ʒu�^& v);

	bool operator==(const �Q�c�ʒu�^& v) const; // == ��r���Z�q
	bool operator!=(const �Q�c�ʒu�^& v) const; // != ��r���Z�q
};


/// <summary>
/// �Q�c�x�N�g���̃N���X�B
/// <para>������r���Z�q�Ƃ��ẮA �u==�v�Ɓu!=�v</para>
/// </summary>
class �Q�c�x�N�g���^ {
public:

	double �w;  // �w����
	double �x;  // �x����

	/// <summary>
	/// �S�Ă̐������O�̃R���X�g���N�^�B
	/// </summary>
	�Q�c�x�N�g���^();


	/// <summary>
	/// �w�����A�x�����A�y�������w�肷��R���X�g���N�^
	/// </summary>
	/// <param name="�w����">�w����</param>
	/// <param name="�x����">�x����</param>
	�Q�c�x�N�g���^(double �w����, double �x����);

	/// <summary>
	/// �ʒu�^�v�f�����̂܂܃x�N�g����
	/// </summary>
	�Q�c�x�N�g���^(�Q�c�ʒu�^ pos);

	/// <summary>
	/// �R�s�[�R���X�g���N�^�����B
	/// </summary>
	�Q�c�x�N�g���^& �Q�c�x�N�g���^::operator=(const �Q�c�x�N�g���^& v);

	/// <summary>
	/// �x�N�g�����Z
	/// </summary>
	�Q�c�x�N�g���^& operator+=(const �Q�c�x�N�g���^& v);

	/// <summary>
	/// �x�N�g�����Z
	/// </summary>
	�Q�c�x�N�g���^& operator-=(const �Q�c�x�N�g���^& v);

	/// <summary>
	/// �x�N�g����k�{��
	/// </summary>
	�Q�c�x�N�g���^& operator*=(double k);

	/// <summary>
	/// �x�N�g����k���̈��
	/// </summary>
	�Q�c�x�N�g���^& operator/=(double k);

	/// <summary>
	/// �P����+(�v���X)
	/// </summary>
	�Q�c�x�N�g���^ operator+()const;

	/// <summary>
	/// �P����+(�}�C�i�X)
	/// </summary>
	�Q�c�x�N�g���^ operator-()const;

	/// <summary>
	/// �Y�������Z�q�B0==�w�����A1==�x���� �̂��ƁB
	/// </summary>
	double& operator[](int i);

	bool operator==(const �Q�c�x�N�g���^& v ) const; // == ��r���Z�q
	bool operator!=(const �Q�c�x�N�g���^& v ) const; // != ��r���Z�q

	/// <summary>
	/// �׃N�g���̒���
	/// </summary>
	double ����()const;

	/// <summary>
	/// �P�ʃx�N�g���ւ̐��K���B
	/// <para>�����O���ƒP�ʃx�N�g���ɏo���Ȃ��̂Œ���</para>
	/// </summary>
	void ���K��();
};

/// <summary>
/// �x�N�g�����Z
/// </summary>
�Q�c�x�N�g���^ operator+(const �Q�c�x�N�g���^& u, const �Q�c�x�N�g���^& v);

/// <summary>
/// �x�N�g�����Z
/// </summary>
�Q�c�x�N�g���^ operator-(const �Q�c�x�N�g���^& u, const �Q�c�x�N�g���^& v);

/// <summary>
/// �x�N�g����k�{��
/// </summary>
�Q�c�x�N�g���^ operator*(double k, const �Q�c�x�N�g���^& v);

/// <summary>
/// �x�N�g����k�{��
/// </summary>
�Q�c�x�N�g���^ operator*(const �Q�c�x�N�g���^& v, double k);

/// <summary>
/// �x�N�g����k���̈��
/// </summary>
�Q�c�x�N�g���^ operator/(const �Q�c�x�N�g���^& v, double k);

/// <summary>
/// �Q�̃x�N�g���̂Ȃ�����
/// </summary>
double operator*(const �Q�c�x�N�g���^& u, const �Q�c�x�N�g���^& v);

/// <summary>
/// �Q�̃x�N�g���̂Ȃ��O��
/// </summary>
double operator%(const �Q�c�x�N�g���^& u, const �Q�c�x�N�g���^& v);

/// <summary>
/// �Q�̃x�N�g���̂Ȃ��p�x
/// </summary>
double �p�x(const �Q�c�x�N�g���^& u, const �Q�c�x�N�g���^& v);

/// <summary>
/// �Q�_�ԍ��W�̍�
/// </summary>
�Q�c�x�N�g���^ operator-(�Q�c�ʒu�^ &p1, �Q�c�ʒu�^ &p2);

/// <summary>
/// <para>�x�N�g�����u���v�u���v�u��v�u�k�v�u�k���v�u�쓌�v�u�k���v�u�쐼�v�̂W���ʂŕ����񉻁B</para>
/// <para>�ł��߂����̂��I�΂��</para>
/// </summary>
string Get_�W���ʕ�����(�Q�c�x�N�g���^ v);

/// <summary>
/// <para>�x�N�g�����u���v�u���v�u��v�u�k�v�̂S���ʂŕ����񉻁B</para>
/// <para>�ł��߂����̂��I�΂��</para>
/// </summary>
string Get_�S���ʕ�����(�Q�c�x�N�g���^ v);

