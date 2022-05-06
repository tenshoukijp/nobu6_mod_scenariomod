/*
 * 大名情報型
 */
#pragma once
#pragma pack(1)

#include <windows.h>

/// <summary>
/// 以下の関数群は全て、動詞・助動詞・名称などの「自動的な変格活用」とも言える文字列を得るための関数群である。
/// 
/// 不特定の武将Aと武将Bの間で会話をする際に、「人物関係」「年齢や性別や職業」「その人物が持つ言葉遣い」などを全て考慮し、
/// 最もふさわしいであろう文字列が返ってくる。
/// </summary>

namespace 関数 {

	// 00（相手に敬意を払う必要がない場合の自称） 
	string ％わし％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 02（その他の場合の自称） 
	string ％私％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 03（所有形容詞）  
	string ％我が％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 04〜07 相手をさげすむ場合「以外」の二人称
	string ％相手％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】			, int 第三者武将番号【配列用】 = 0xFFFF);

	// 08 相手をさげすむ場合の二人称
	string ％罵倒相手％	(int 自分武将番号【配列用】, int 相手武将番号【配列用】			, int 第三者武将番号【配列用】 = 0xFFFF);

	// 09〜0D 三名をさげすむ場合「以外」の三人称
	string ％三名％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】			, int 第三者武将番号【配列用】);

	// 0E（第三者をさげすむ場合の三人称） 
	string ％罵倒三名％	(int 自分武将番号【配列用】, int 相手武将番号【配列用】			, int 第三者武将番号【配列用】);

}


namespace 関数 {

	// 0F 〜です 〜だ じゃ
	string ％です％			(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 11 〜ですか 〜でござるか 〜か
	string ％ですか％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 13 〜でしょう 〜じゃろう 〜であろう 〜だろう
	string ％でしょう％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 15 〜でした 〜じゃった 〜であった 〜だった
	string ％でした％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 17 〜あります 〜ございます 〜ござる 〜ある 〜おじゃる
	string ％あります％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 19 〜ありません 〜ございません 〜ござらぬ 〜ない 〜おじゃらぬ 〜ありませぬ
	string ％ありません％	(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 1B 〜します 〜いたす 〜する
	string ％します％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 1D 〜しません 〜いたさぬ 〜せぬ 〜せん 〜しませぬ
	string ％しません％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 1F 〜しましょう 〜いたそう 〜しよう
	string ％しましょう％	(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);


	// 21 〜いましょう 〜おう  (言いましょうなど)
	string ％いましょう％	(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 23 〜きましょう 〜こう  (行きましょうなど)
	string ％きましょう％	(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 25 〜しましょう 〜そう  (？… ％しましょう％の方が良いか)
	string ％しましょう２％	(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 27 〜ちましょう 〜とう  (待ちましょうなど)
	string ％ちましょう％	(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 29 〜みましょう 〜もう  (攻め込みましょうなど)
	string ％みましょう％	(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 2B 〜ましょう 〜よう  (その他の一般パターン。立てましょうなど)
	string ％ましょう％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 2D 〜りましょう 〜ろう  (参りましょうなど)
	string ％りましょう％	(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 31 〜ぎましょう 〜ごう  (急ぎましょうなど)
	string ％ぎましょう％	(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 33 〜びましょう 〜ぼう　(遊びましょうなど)
	string ％びましょう％	(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);


	// 35 〜います 〜ござる 〜おる 〜いる 〜おじゃる 〜おります
	string ％います％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 37 〜いません 〜ござらぬ 〜おらぬ 〜おらん 〜おじゃらぬ 〜おりませぬ
	string ％いません％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 39 〜いました 〜ござった 〜おった 〜いた 〜おじゃった 〜おりました
	string ％いました％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 3B 〜ます 〜る 〜ります
	string ％ます％			(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 3D 〜りません 〜らぬ
	string ％りません％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 3F 〜ません 〜ぬ 〜ねえ 〜ませぬ
	string ％ません％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 41 〜ました 〜た
	string ％ました％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 43 〜りました 〜った
	string ％りました％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 45 〜ませんでした 〜なかった
	string ％ませんでした％	(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 47 〜思います 〜存じます 〜思う
	string ％思います％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 49 〜参りました 〜参上しました 〜参った
	string ％参りました％	(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 4B 〜くだされ 〜下さい 〜くれ
	string ％くだされ％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 4D 〜すみません 〜申し訳ない 〜すまぬ 〜すまん 〜ごめんなさい
	string ％すみません％	(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 4F 〜願います 〜お願いいたす 〜願おう 〜願う 〜お願いします
	string ％願います％		(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);

	// 51 〜よい 〜よろしい
	string ％よい％			(int 自分武将番号【配列用】, int 相手武将番号【配列用】 = 0xFFFF	, int 第三者武将番号【配列用】 = 0xFFFF);
}


namespace 関数 {
	// 〜か 〜ね
	string ％か（１）％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// 〜か 〜なの
	string ％か（２）％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// 〜か 〜わ
	string ％か（３）％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// 〜か 〜かしら
	string ％か（４）％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// 〜ぞ 〜ぜ 〜ぞよ 〜わ
	string ％ぞ（１）％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// 〜ぞ 〜ぜ 〜ぞよ 〜わよ
	string ％ぞ（２）％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// 〜な 〜わ
	string ％な（１）％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// 〜な 〜ね
	string ％な（２）％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// 〜(無し) 〜わ
	string ％わ（１）％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// 〜わ 〜わい
	string ％わ（２）％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// 〜なあ 〜のお 〜ねえ 
	string ％なあ％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// 〜お 〜(無し)
	string ％お（１）％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// 〜お 〜(無し)
	string ％お（２）％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// ははは ふふふ くくく あはは わはは ふっ うふふ おほほ 
	string ％ははは％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// 〜い 〜き
	string ％い％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// うむむ まあ 
	string ％うむむ％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// おお まあ
	string ％おお％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// つまらぬ… おもしろくありません 
	string ％つまらぬ…％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// やっ し 
	string ％やっ％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// ち てし
	string ％ち％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// れ られよ 
	string ％れ％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// しんぜよう くれよう しんぜましょう 
	string ％しんぜよう％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// 一族 親子 姉妹 姉弟 兄妹 夫婦 兄弟 姉妹 姉弟 兄妹 
	string ％一族％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// でござる だぞ、ははは でおじゃるぞえ ですわ 
	string ％でござる％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// すな しますな 
	string ％すな％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// てみよ なさい
	string ％てみよ％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);

	// よ ませ
	string ％よ％(int 自分武将番号【配列用】, int 相手武将番号【配列用】, int 第三者武将番号【配列用】 = 0xFFFF);
}

