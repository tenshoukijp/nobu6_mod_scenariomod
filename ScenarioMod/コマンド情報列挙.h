#pragma once

namespace 列挙{

	/// <summary>
	/// <para>主に「On_プレイヤコマンド発生直前《メイン画面》」のメソッドで使用する。</para>
	/// <para>メイン画面で、プレイヤコマンドが「発生」したかの判定用。</para>
	/// </summary>
	namespace メイン画面 {
		namespace メインコマンド名 {
			enum {
				本城 = 0x12C, 支城 = 0x12D, 城 = 0x12E, 一覧 = 0x12F, 地図 = 0x130, 機能 = 0x131, 静観 = 0x132,
				教育 = 0x133, 人事 = 0x134, 軍団 = 0x135, 物資 = 0x136, 外交 = 0x137, 調略 = 0x138, 戦争 = 0x139, 評定 = 0x13A,
				内政 = 0x13B, 軍事 = 0x13C, 会見 = 0x13D
			};
		}

		namespace サブコマンド名 {
			namespace 一覧 {
				enum { 勢力 = (メインコマンド名::一覧 * 1000), 軍団, 所領, 家臣, 家宝, 官位 };
			}
			namespace 機能 {
				enum { 記録 = (メインコマンド名::機能 * 1000), 呼出, 環境, 終了, 編集 };
			}
			namespace 教育 {
				enum { 講義 = (メインコマンド名::教育 * 1000), 披露 };
			}
			namespace 人事 {
				enum { 登用 = (メインコマンド名::人事 * 1000), 昇進, 褒美, 隠居, 縁組, 賞罰 };
			}
			namespace 軍団 {
				enum { 任命 = (メインコマンド名::軍団 * 1000), 分配, 合流, 入替, 再任 };
			}
			namespace 物資 {
				enum { 購入 = (メインコマンド名::物資 * 1000), 売却, 輸送, 徴発 };
			}
			namespace 外交 {
				enum { 同盟 = (メインコマンド名::外交 * 1000), 婚姻, 手切, 脅迫, 朝廷 };
			}
			namespace 調略 {
				enum { 内応 = (メインコマンド名::調略 * 1000), 謀略 };
			}
			namespace 内政 {
				enum { 開墾 = (メインコマンド名::内政 * 1000), 商業, 築城, 施し };
			}
			namespace 軍事 {
				enum { 徴兵 = (メインコマンド名::軍事 * 1000), 訓練, 編成, 移動, 呼寄 };
			}
		}


		/// <summary>メイン画面の各コマンドの消費行動力を設定する用途
		/// <para>「 Set_コマンド行動力」の関数で使用する。</para>
		/// </summary>
		namespace 行動力コマンド名 {
			const int 講義 = 0x419386;
			const int 披露 = 0x419D6A;
			const int 編成 = 0x47A9F0;
			const int 徴兵 = 0x47A1FF;
			const int 登用 = 0x48E343;
			const int 褒美 = 0x40140C;
			const int 物資 = 0x4468A6;
			const int 戦争 = 0x4A0CD7;
			const int 同盟 = 0x423EFE;
			const int 婚姻 = 0x4255CF;
			const int 手切 = 0x426ACF;
			const int 脅迫 = 0x4258F8;
			const int 朝廷 = 0x42709F;
			const int 内応 = 0x402BC0;
			const int 謀略 = 0x40341C;
			const int 評定 = 0x41B2B5;
			const int 軍団－任命 = 0x45ECE4;
			const int 軍団－再任・分配・合流 = 0x45F0AD;
			const int 内政・訓練・昇進 = 0x42E472;
		};

	}


	/// <summary>
	/// <para>主に「On_戦闘コマンド表示直前《戦争画面》」や「On_基本コマンド表示直前《戦争画面》」で使用する。</para>
	/// <para>「Set_コマンド名」の関数で使用する。</para>
	/// </summary>
	namespace 戦争画面 {

		namespace 戦闘コマンド名 {
			const int 通常攻撃 = 0;
			const int 一斉攻撃 = 1;
			const int 突撃 = 2;
			const int 鉄砲攻撃 = 3;
			const int 弓攻撃 = 3; // 鉄砲と同じスロットを使うので注意せよ。
			const int 大砲攻撃 = 4;
		}

		namespace 基本コマンド名 {
			const int 鼓舞 = 100;
			const int 城外 = 101;
			const int 退却 = 102;
			const int 内応 = 103;
			const int 技能 = 104;
			const int 挑発 = 105;
			const int 煽動 = 106;
			const int 混乱 = 107;
			const int 火攻め = 108;
			const int 暗殺 = 109;
			const int 徴兵 = 110;
			const int 一喝 = 111;
		}
	}
}

using namespace 列挙;