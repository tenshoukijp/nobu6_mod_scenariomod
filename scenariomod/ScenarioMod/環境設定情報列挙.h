#pragma once


namespace 列挙 {

	namespace 環境設定 {

		namespace 効果音 {
			static const int ＯＮ = 1;
			static const int ＯＦＦ = 0;
		};

		namespace 音楽 {
			static const int ＯＮ = 1;
			static const int ＯＦＦ = 0;
		};

		// ムービーはＯＮとＯＦＦで意味論と、内部の真偽値が逆なので注意せよ!!
		namespace ムービー {
			static const int ＯＮ = 0;
			static const int ＯＦＦ = 1;
		};

		namespace 他国の戦争 {
			static const int 見る = 2;
			static const int 任意 = 1;
			static const int 見ない = 0;
		};

		namespace 表示速度 {
			static const int ０ = 0;
			static const int １ = 1;
			static const int ２ = 2;
			static const int ３ = 3;
			static const int ∞ = 4;
		};

		namespace 難易度 {
			static const int 楽 = 0;
			static const int 初 = 1;
			static const int 中 = 2;
			static const int 上 = 3;
			static const int 難 = 4;
		};
	}

	namespace 環境設定拡張 {

		namespace 年号表示 {
			static const int 元号 = 1;
			static const int 西暦 = 0;
		};

		namespace 表示位置記憶 {
			static const int マウス = 1;
			static const int 記憶 = 0;
		};

		namespace  表示切替マップ {
			static const int 連動 = 1;
			static const int 非連動 = 0;
		};

		namespace 戦争頻度 {
			static const int 好戦 = 1;
			static const int 理知 = 0;
		};

		namespace 計略頻度 {
			static const int 多い = 1;
			static const int 少ない = 0;
		};

		namespace 死亡頻度 {
			static const int 多い = 1;
			static const int 少ない = 0;
		};

		namespace 自国の戦争 {
			static const int 任意 = 2;
			static const int 従来 = 1;
			static const int 見る = 0;
		};

		namespace 編集機能 {
			static const int 有り = 1;
			static const int 無し = 0;
		};

		namespace 情報表示 {
			static const int 最小 = 2;
			static const int 少ない = 1;
			static const int 普通 = 0;
		};

		namespace 武将行動志願 {
			static const int 有り = 1;
			static const int 無し = 0;
		};

		namespace 姫武将志願 {
			static const int 毎回 = 2;
			static const int 従来 = 1;
			static const int 無し = 0;
		};
	}
}


using namespace 列挙::環境設定;
using namespace 列挙::環境設定拡張;