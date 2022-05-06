
// ���ʂ̂R�c�x�N�g���^�B
#pragma once

#include "�⏕���C�u����.h"


/// <summary>
/// �R�c�ʒu�i������3DPosition�Ƃ������T�O)�̃N���X�B
/// <para>������r���Z�q�Ƃ��ẮA �u==�v�Ɓu!=�v</para>
/// <para>���A
/// <code>
/// �R�c�x�N�g���^ v = p2 - p1
/// </code>
/// </para>
/// <para>�Ƃ����悤�ɁA�`�n�_����a�n�_���������ƂŁA�P�̕����x�N�g���ƂȂ�܂��B</para>
/// </summary>
struct �R�c�ʒu�^ {

	double �w;  // �w�ʒu
	double �x;  // �x�ʒu
	double �y;  // �y�ʒu

	/// <summary>
	/// �w�ʒu�A�x�ʒu�A�y�ʒu���w�肷��R���X�g���N�^
	/// </summary>
	/// <param name="�w�ʒu">�w�ʒu</param>
	/// <param name="�x�ʒu">�x�ʒu</param>
	/// <param name="�y�ʒu">�y�ʒu</param>
	�R�c�ʒu�^(double �w�ʒu, double �x�ʒu, double �y�ʒu) : �w(�w�ʒu), �x(�x�ʒu), �y(�y�ʒu) {}

	/// <summary>
	/// ���_�ʒu�̃R���X�g���N�^�B
	/// </summary>
	�R�c�ʒu�^() : �w(0), �x(0), �y(0) {}

	/// <summary>
	/// �R�s�[�R���X�g���N�^�����B
	/// </summary>
	�R�c�ʒu�^& operator=(const �R�c�ʒu�^& v);

	bool operator==(const �R�c�ʒu�^& v) const; // == ��r���Z�q
	bool operator!=(const �R�c�ʒu�^& v) const; // != ��r���Z�q
};


/// <summary>
/// �R�c�x�N�g���̃N���X�B
/// <para>������r���Z�q�Ƃ��ẮA �u==�v�Ɓu!=�v</para>
/// </summary>
class �R�c�x�N�g���^ {
public:
	
	double �w;  // �w����
	double �x;  // �x����
	double �y;  // �y����

	/// <summary>
	/// �S�Ă̐������O�̃R���X�g���N�^�B
	/// </summary>
	�R�c�x�N�g���^();

	/// <summary>
	/// �w�����A�x�����A�y�������w�肷��R���X�g���N�^
	/// </summary>
	/// <param name="�w����">�w����</param>
	/// <param name="�x����">�x����</param>
	/// <param name="�y����">�y����</param>
	�R�c�x�N�g���^(double �w����, double �x����, double �y����);

	/// <summary>
	/// �ʒu�^�v�f�����̂܂܃x�N�g����
	/// </summary>
	�R�c�x�N�g���^(�R�c�ʒu�^ pos);
	
	/// <summary>
	/// �R�s�[�R���X�g���N�^�����B
	/// </summary>
	�R�c�x�N�g���^& �R�c�x�N�g���^::operator=(const �R�c�x�N�g���^& v);
	
	/// <summary>
	/// �x�N�g�����Z
	/// </summary>
	�R�c�x�N�g���^& operator+=(const �R�c�x�N�g���^& v);

	/// <summary>
	/// �x�N�g�����Z
	/// </summary>
	�R�c�x�N�g���^& operator-=(const �R�c�x�N�g���^& v);

	/// <summary>
	/// �x�N�g����k�{��
	/// </summary>
	�R�c�x�N�g���^& operator*=(double k);

	/// <summary>
	/// �x�N�g����k���̈��
	/// </summary>
	�R�c�x�N�g���^& operator/=(double k);

	/// <summary>
	/// �P����+(�v���X)
	/// </summary>
	�R�c�x�N�g���^ operator+()const;

	/// <summary>
	/// �P����+(�}�C�i�X)
	/// </summary>
	�R�c�x�N�g���^ operator-()const;
	
	/// <summary>
	/// �Y�������Z�q�B0==�w�����A1==�x�����A2==�y���� �̂��ƁB
	/// </summary>
	double& operator[](int i);
    
	bool operator==(const �R�c�x�N�g���^& v ) const; // == ��r���Z�q
	bool operator!=(const �R�c�x�N�g���^& v ) const; // != ��r���Z�q
	
	/// <summary>
	/// �׃N�g���̒���
	/// </summary>
	double ����() const;
	
	/// <summary>
	/// �P�ʃx�N�g���ւ̐��K���B
	/// <para>�����O���ƒP�ʃx�N�g���ɏo���Ȃ��̂Œ���</para>
	/// </summary>
	void ���K��();
};

/// <summary>
/// �x�N�g�����Z
/// </summary>
�R�c�x�N�g���^ operator+(const �R�c�x�N�g���^& u, const �R�c�x�N�g���^& v);

/// <summary>
/// �x�N�g�����Z
/// </summary>
�R�c�x�N�g���^ operator-(const �R�c�x�N�g���^& u, const �R�c�x�N�g���^& v);

/// <summary>
/// �x�N�g����k�{��
/// </summary>
�R�c�x�N�g���^ operator*(double k, const �R�c�x�N�g���^& v);

/// <summary>
/// �x�N�g����k�{��
/// </summary>
�R�c�x�N�g���^ operator*(const �R�c�x�N�g���^& v, double k);

/// <summary>
/// �x�N�g����k���̈��
/// </summary>
�R�c�x�N�g���^ operator/(const �R�c�x�N�g���^& v, double k);

/// <summary>
/// �Q�̃x�N�g���̂Ȃ�����
/// </summary>
double operator*(const �R�c�x�N�g���^& u, const �R�c�x�N�g���^& v);

/// <summary>
/// �Q�̃x�N�g���̂Ȃ��O��
/// </summary>
�R�c�x�N�g���^ operator%(const �R�c�x�N�g���^& u, const �R�c�x�N�g���^& v);

/// <summary>
/// �Q�̃x�N�g���̂Ȃ��p�x
/// </summary>
double �p�x(const �R�c�x�N�g���^& u, const �R�c�x�N�g���^& v);

/// <summary>
/// �Q�_�ԍ��W�̍�
/// </summary>
�R�c�x�N�g���^ operator-(�R�c�ʒu�^ &p1, �R�c�ʒu�^ &p2);

