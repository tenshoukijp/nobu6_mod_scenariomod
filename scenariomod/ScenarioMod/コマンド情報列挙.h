#pragma once

namespace ��{

	/// <summary>
	/// <para>��ɁuOn_�v���C���R�}���h�������O�s���C����ʁt�v�̃��\�b�h�Ŏg�p����B</para>
	/// <para>���C����ʂŁA�v���C���R�}���h���u�����v�������̔���p�B</para>
	/// </summary>
	namespace ���C����� {
		namespace ���C���R�}���h�� {
			enum {
				�{�� = 0x12C, �x�� = 0x12D, �� = 0x12E, �ꗗ = 0x12F, �n�} = 0x130, �@�\ = 0x131, �Ê� = 0x132,
				���� = 0x133, �l�� = 0x134, �R�c = 0x135, ���� = 0x136, �O�� = 0x137, ���� = 0x138, �푈 = 0x139, �]�� = 0x13A,
				���� = 0x13B, �R�� = 0x13C, � = 0x13D
			};
		}

		namespace �T�u�R�}���h�� {
			namespace �ꗗ {
				enum { ���� = (���C���R�}���h��::�ꗗ * 1000), �R�c, ����, �Ɛb, �ƕ�, ���� };
			}
			namespace �@�\ {
				enum { �L�^ = (���C���R�}���h��::�@�\ * 1000), �ďo, ��, �I��, �ҏW };
			}
			namespace ���� {
				enum { �u�` = (���C���R�}���h��::���� * 1000), ��I };
			}
			namespace �l�� {
				enum { �o�p = (���C���R�}���h��::�l�� * 1000), ���i, �J��, �B��, ���g, �ܔ� };
			}
			namespace �R�c {
				enum { �C�� = (���C���R�}���h��::�R�c * 1000), ���z, ����, ����, �ĔC };
			}
			namespace ���� {
				enum { �w�� = (���C���R�}���h��::���� * 1000), ���p, �A��, ���� };
			}
			namespace �O�� {
				enum { ���� = (���C���R�}���h��::�O�� * 1000), ����, ���, ����, ���� };
			}
			namespace ���� {
				enum { ���� = (���C���R�}���h��::���� * 1000), �d�� };
			}
			namespace ���� {
				enum { �J�� = (���C���R�}���h��::���� * 1000), ����, �z��, �{�� };
			}
			namespace �R�� {
				enum { ���� = (���C���R�}���h��::�R�� * 1000), �P��, �Ґ�, �ړ�, �Ċ� };
			}
		}


		/// <summary>���C����ʂ̊e�R�}���h�̏���s���͂�ݒ肷��p�r
		/// <para>�u Set_�R�}���h�s���́v�̊֐��Ŏg�p����B</para>
		/// </summary>
		namespace �s���̓R�}���h�� {
			const int �u�` = 0x419386;
			const int ��I = 0x419D6A;
			const int �Ґ� = 0x47A9F0;
			const int ���� = 0x47A1FF;
			const int �o�p = 0x48E343;
			const int �J�� = 0x40140C;
			const int ���� = 0x4468A6;
			const int �푈 = 0x4A0CD7;
			const int ���� = 0x423EFE;
			const int ���� = 0x4255CF;
			const int ��� = 0x426ACF;
			const int ���� = 0x4258F8;
			const int ���� = 0x42709F;
			const int ���� = 0x402BC0;
			const int �d�� = 0x40341C;
			const int �]�� = 0x41B2B5;
			const int �R�c�|�C�� = 0x45ECE4;
			const int �R�c�|�ĔC�E���z�E���� = 0x45F0AD;
			const int �����E�P���E���i = 0x42E472;
		};

	}


	/// <summary>
	/// <para>��ɁuOn_�퓬�R�}���h�\�����O�s�푈��ʁt�v��uOn_��{�R�}���h�\�����O�s�푈��ʁt�v�Ŏg�p����B</para>
	/// <para>�uSet_�R�}���h���v�̊֐��Ŏg�p����B</para>
	/// </summary>
	namespace �푈��� {

		namespace �퓬�R�}���h�� {
			const int �ʏ�U�� = 0;
			const int ��čU�� = 1;
			const int �ˌ� = 2;
			const int �S�C�U�� = 3;
			const int �|�U�� = 3; // �S�C�Ɠ����X���b�g���g���̂Œ��ӂ���B
			const int ��C�U�� = 4;
		}

		namespace ��{�R�}���h�� {
			const int �ە� = 100;
			const int ��O = 101;
			const int �ދp = 102;
			const int ���� = 103;
			const int �Z�\ = 104;
			const int ���� = 105;
			const int ���� = 106;
			const int ���� = 107;
			const int �΍U�� = 108;
			const int �ÎE = 109;
			const int ���� = 110;
			const int �ꊅ = 111;
		}
	}
}

using namespace ��;