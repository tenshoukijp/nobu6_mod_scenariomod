/*
 * �喼���^
 */
#pragma once
#pragma pack(1)

#include <windows.h>

/// <summary>
/// �ȉ��̊֐��Q�͑S�āA�����E�������E���̂Ȃǂ́u�����I�ȕϊi���p�v�Ƃ������镶����𓾂邽�߂̊֐��Q�ł���B
/// 
/// �s����̕���A�ƕ���B�̊Ԃŉ�b������ۂɁA�u�l���֌W�v�u�N��␫�ʂ�E�Ɓv�u���̐l���������t�����v�Ȃǂ�S�čl�����A
/// �ł��ӂ��킵���ł��낤�����񂪕Ԃ��Ă���B
/// </summary>

namespace �֐� {

	// 00�i����Ɍh�ӂ𕥂��K�v���Ȃ��ꍇ�̎��́j 
	string ���킵��		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 02�i���̑��̏ꍇ�̎��́j 
	string ������		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 03�i���L�`�e���j  
	string ���䂪��		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 04�`07 ������������ޏꍇ�u�ȊO�v�̓�l��
	string �����聓		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z			, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 08 ������������ޏꍇ�̓�l��
	string ���l�|���聓	(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z			, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 09�`0D �O�����������ޏꍇ�u�ȊO�v�̎O�l��
	string ���O����		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z			, int ��O�ҕ����ԍ��y�z��p�z);

	// 0E�i��O�҂��������ޏꍇ�̎O�l�́j 
	string ���l�|�O����	(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z			, int ��O�ҕ����ԍ��y�z��p�z);

}


namespace �֐� {

	// 0F �`�ł� �`�� ����
	string ���ł���			(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 11 �`�ł��� �`�ł����邩 �`��
	string ���ł�����		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 13 �`�ł��傤 �`����낤 �`�ł��낤 �`���낤
	string ���ł��傤��		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 15 �`�ł��� �`������� �`�ł����� �`������
	string ���ł�����		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 17 �`����܂� �`�������܂� �`������ �`���� �`�������
	string ������܂���		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 19 �`����܂��� �`�������܂��� �`������� �`�Ȃ� �`�������� �`����܂���
	string ������܂���	(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 1B �`���܂� �`������ �`����
	string �����܂���		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 1D �`���܂��� �`�������� �`���� �`���� �`���܂���
	string �����܂���		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 1F �`���܂��傤 �`�������� �`���悤
	string �����܂��傤��	(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);


	// 21 �`���܂��傤 �`����  (�����܂��傤�Ȃ�)
	string �����܂��傤��	(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 23 �`���܂��傤 �`����  (�s���܂��傤�Ȃ�)
	string �����܂��傤��	(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 25 �`���܂��傤 �`����  (�H�c �����܂��傤���̕����ǂ���)
	string �����܂��傤�Q��	(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 27 �`���܂��傤 �`�Ƃ�  (�҂��܂��傤�Ȃ�)
	string �����܂��傤��	(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 29 �`�݂܂��傤 �`����  (�U�ߍ��݂܂��傤�Ȃ�)
	string ���݂܂��傤��	(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 2B �`�܂��傤 �`�悤  (���̑��̈�ʃp�^�[���B���Ă܂��傤�Ȃ�)
	string ���܂��傤��		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 2D �`��܂��傤 �`�낤  (�Q��܂��傤�Ȃ�)
	string ����܂��傤��	(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 31 �`���܂��傤 �`����  (�}���܂��傤�Ȃ�)
	string �����܂��傤��	(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 33 �`�т܂��傤 �`�ڂ��@(�V�т܂��傤�Ȃ�)
	string ���т܂��傤��	(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);


	// 35 �`���܂� �`������ �`���� �`���� �`������� �`����܂�
	string �����܂���		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 37 �`���܂��� �`������� �`����� �`����� �`�������� �`����܂���
	string �����܂���		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 39 �`���܂��� �`�������� �`������ �`���� �`��������� �`����܂���
	string �����܂�����		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 3B �`�܂� �`�� �`��܂�
	string ���܂���			(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 3D �`��܂��� �`���
	string ����܂���		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 3F �`�܂��� �`�� �`�˂� �`�܂���
	string ���܂���		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 41 �`�܂��� �`��
	string ���܂�����		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 43 �`��܂��� �`����
	string ����܂�����		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 45 �`�܂���ł��� �`�Ȃ�����
	string ���܂���ł�����	(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 47 �`�v���܂� �`�����܂� �`�v��
	string ���v���܂���		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 49 �`�Q��܂��� �`�Q�サ�܂��� �`�Q����
	string ���Q��܂�����	(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 4B �`�������� �`������ �`����
	string ���������ꁓ		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 4D �`���݂܂��� �`�\����Ȃ� �`���܂� �`���܂� �`���߂�Ȃ���
	string �����݂܂���	(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 4F �`�肢�܂� �`���肢������ �`�肨�� �`�肤 �`���肢���܂�
	string ���肢�܂���		(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// 51 �`�悢 �`��낵��
	string ���悢��			(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z = 0xFFFF	, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);
}


namespace �֐� {
	// �`�� �`��
	string �����i�P�j��(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �`�� �`�Ȃ�
	string �����i�Q�j��(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �`�� �`��
	string �����i�R�j��(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �`�� �`������
	string �����i�S�j��(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �`�� �`�� �`���� �`��
	string �����i�P�j��(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �`�� �`�� �`���� �`���
	string �����i�Q�j��(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �`�� �`��
	string ���ȁi�P�j��(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �`�� �`��
	string ���ȁi�Q�j��(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �`(����) �`��
	string ����i�P�j��(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �`�� �`�킢
	string ����i�Q�j��(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �`�Ȃ� �`�̂� �`�˂� 
	string ���Ȃ���(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �`�� �`(����)
	string �����i�P�j��(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �`�� �`(����)
	string �����i�Q�j��(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �͂͂� �ӂӂ� ������ ���͂� ��͂� �ӂ� ���ӂ� ���ق� 
	string ���͂͂́�(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �`�� �`��
	string ������(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// ���ނ� �܂� 
	string �����ނށ�(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// ���� �܂�
	string ��������(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �܂�ʁc �������낭����܂��� 
	string ���܂�ʁc��(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// ��� �� 
	string �������(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �� �Ă�
	string ������(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �� ���� 
	string ���ꁓ(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// ���񂺂悤 ����悤 ���񂺂܂��傤 
	string �����񂺂悤��(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �ꑰ �e�q �o�� �o�� �Z�� �v�w �Z�� �o�� �o�� �Z�� 
	string ���ꑰ��(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �ł����� �����A�͂͂� �ł�����邼�� �ł��� 
	string ���ł����道(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// ���� ���܂��� 
	string �����ȁ�(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �Ă݂� �Ȃ���
	string ���Ă݂恓(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);

	// �� �܂�
	string ���恓(int ���������ԍ��y�z��p�z, int ���蕐���ԍ��y�z��p�z, int ��O�ҕ����ԍ��y�z��p�z = 0xFFFF);
}

