#pragma once

/// <summary>
/// �Z�[�u�f�[�^�́u���[�h�v�Ɓu�Z�[�u�v�̓����^�C�~���O�ŁA�ʓr�t�@�C����ǂݏ������邽�߂̃T�|�[�g�N���X�B
/// </summary>
template <typename T�\����> class �g���Z�[�u�f�[�^���^ {

public:

	/// <summary>
	/// <para>�g���Z�[�u�f�[�^�̎��́B</para>
	/// <para>���̕ϐ���Z�����O�̎Q�ƕϐ��ŗ��p���邱�Ƃ�z�肵�Ă���B</para>
	/// </summary>
	T�\���� �g���p�����^;

	�g���Z�[�u�f�[�^���^() {
		static_assert(std::is_pod<T�\����>::value, "EXTENSION Save Data STRUCT is NOT TRIVIAL"); // ��
		Do_�������N���A();
	}


private:
	struct �I�[���Z�[�u�f�[�^EX {
		T�\���� �X���b�g�g���Z�[�u�f�[�^[8];
	};

	�I�[���Z�[�u�f�[�^EX �S�g���Z�[�u�f�[�^;


private:
	string Get_�g���Z�[�u�f�[�^��(string �Z�[�u�t�@�C����) {
		string �g���Z�[�u�t�@�C���� = �Z�[�u�t�@�C����;
		�g���Z�[�u�t�@�C���� += "EX";
		return �g���Z�[�u�t�@�C����;
	}

	void Load_�g���Z�[�u�f�[�^(string �Z�[�u�t�@�C����) {
		string �t�@�C���� = Get_�g���Z�[�u�f�[�^��(�Z�[�u�t�@�C����);

		FILE *fp = fopen(�t�@�C����.c_str(), "rb");
		if (fp) {
			// ���������S�f�[�^���킹�Đ����K���x�܂ł��낤����A�P���Ńt�@�C�����\���̂̔z��ւƃV���A���R�s�v
			int len = fread(&�S�g���Z�[�u�f�[�^, sizeof(�I�[���Z�[�u�f�[�^EX), 1, fp); // �{���̓G���[����������B
			fclose(fp);
		}
	}

	void Save_�g���Z�[�u�f�[�^(string �Z�[�u�t�@�C����) {
		string �t�@�C���� = Get_�g���Z�[�u�f�[�^��(�Z�[�u�t�@�C����);

		FILE *fp = fopen(�t�@�C����.c_str(), "wb");
		if (fp) {
			// ���������S�f�[�^���킹�Đ����K���x�܂ł��낤����A�P���ō\���̂̔z�񁨃t�@�C���ւƃV���A���R�s�v
			int len = fwrite(&�S�g���Z�[�u�f�[�^, sizeof(�I�[���Z�[�u�f�[�^EX), 1, fp); // �{���̓G���[����������B
			fclose(fp);
		}
	}

public:
	/// <summary>
	/// �u�J�X�^��::On_�Z�[�u�f�[�^�Ǎ����v���ŁA���̃��\�b�h���Ăяo���悤�ɂ���̂���ʓI�Ȏg�����B
	/// </summary>
	void On_�Z�[�u�f�[�^�Ǎ���(int �X���b�g�ԍ�, string �Z�[�u�t�@�C����) {
		// �S�ẴX���b�g�̃f�[�^��ǂݍ���ł��܂��B
		Load_�g���Z�[�u�f�[�^(�Z�[�u�t�@�C����);

		int IX = �X���b�g�ԍ� - 1;
		// ���[�h�����S�f�[�^�̂����A�u�Ή�����X���b�g�̊g�������f�[�^�v���A�u�ҏW�p�f�[�^�̈�v�ɃR�s�[
		memcpy(&�g���p�����^, &�S�g���Z�[�u�f�[�^.�X���b�g�g���Z�[�u�f�[�^[IX], sizeof(�g���p�����^));
	}

	/// <summary>
	/// �u�J�X�^��::On_�Z�[�u�f�[�^�ۑ����v���ŁA���̃��\�b�h���Ăяo���悤�ɂ���̂���ʓI�Ȏg�����B
	/// </summary>
	void On_�Z�[�u�f�[�^�ۑ���(int �X���b�g�ԍ�, string �Z�[�u�t�@�C����) {
		// �S�ẴX���b�g�̃f�[�^��ǂݍ���ł��܂��B
		Load_�g���Z�[�u�f�[�^(�Z�[�u�t�@�C����);

		int IX = �X���b�g�ԍ� - 1;
		// �S�g���Z�[�u�f�[�^�́u�Ή�����X���b�g�����v�ɁA�u�ҏW�p�f�[�^�̈�̏��v���܂�܂�R�s�[
		memcpy(&�S�g���Z�[�u�f�[�^.�X���b�g�g���Z�[�u�f�[�^[IX], &�g���p�����^, sizeof(�g���p�����^));

		Save_�g���Z�[�u�f�[�^(�Z�[�u�t�@�C����);
	}

	/// <summary>
	/// ��������̊g���Z�[�u�f�[�^���N���A����B
	/// </summary>
	void Do_�������N���A() {
		ZeroMemory(&�S�g���Z�[�u�f�[�^, sizeof(�S�g���Z�[�u�f�[�^));
		ZeroMemory(&�g���p�����^, sizeof(�g���p�����^));
	}
};


