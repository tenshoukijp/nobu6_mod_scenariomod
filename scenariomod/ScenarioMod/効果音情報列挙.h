#pragma once


/*

// 天翔記内にある効果音を番号で指定して再生する。
/*
リソース番号	使われ所
601	ターン開始
602	成功
603	失敗
604	豊作
605	凶作
606	台風
607	地震
608	斬首
609	通常戦闘、メイン画面での戦争時、剣技披露の太刀
610	突撃時、何度も鳴る。708と同時になる。
611	大砲発射
612	大砲ピューン
613	落城・着弾
614	鉄砲
615	門叩き、桶狭間のイベント時にも利用
616	開門
617	壁越え（ｼｭｼｭｼｭｼｭ）
618	一喝
619	挑発・混乱
620	滅亡・悲しいイベント
701	戦争突入
702	謁見（外交）
703	朝廷
704	夏
705	秋
706	冬
707	春
708	突撃時の継続音 610と同時に鳴る。
709	勝ち鬨
710	大砲着弾・鉄砲打たれ時
711	雨
712	雷（台風時）
713	雪

//-----------フル効果音キット
714	城占拠
715	炎メラメラ
716 弓
717 鉄壁音
721 鉄砲弾返し
*/
namespace 列挙 {
	namespace 音 {
		namespace 効果音音源 {
			const int ターン開始 = 601;
			const int 成功 = 602;
			const int 失敗 = 603;
			const int 豊作 = 604;
			const int 凶作 = 605;
			const int 台風 = 606;
			const int 地震 = 607;
			const int 斬首 = 608;
			const int 交戦 = 609;
			const int 突撃 = 610;
			const int 大砲発射 = 611;
			const int 大砲ピューン = 612;
			const int 落城・着弾 = 613;
			const int 鉄砲 = 614;
			const int 門叩き = 615;
			const int 開門 = 616;
			const int 壁越え = 617;
			const int 一喝 = 618;
			const int 挑発・混乱 = 619;
			const int 滅亡・悲劇 = 620;
			const int 戦争突入 = 701;
			const int 謁見 = 702;
			const int 朝廷 = 703;
			const int 夏 = 704;
			const int 秋 = 705;
			const int 冬 = 706;
			const int 春 = 707;
			const int 突撃継続 = 708;
			const int 勝ち鬨 = 709;
			const int 悲鳴 = 710;
			const int 雨 = 711;
			const int 雷 = 712;
			const int 雪 = 713;
			const int 城占拠 = 714;
			const int 炎メラメラ = 715;
			const int 弓 = 716;
			const int 鉄壁音 = 717;
			const int 鉄砲弾返し = 721;
		};


		namespace 効果音ループ {
			const int ＯＦＦ = 0;
			const int ＯＮ = 1;
		};

	}
}



using namespace 列挙::音;