#include <cassert>
#include "ƒQ[ƒ€ƒf[ƒ^\‘¢.h"


int DeNormalizeDaimyoYakusyokuValue(int iYakusyokuValue) {
	switch (iYakusyokuValue) {
	case –ğE::ªˆÎ‘å«ŒR:
		return 0x01;
	case –ğE::ŠÇ—Ì:
		return 0x02;
	case –ğE::ŠÖ“ŒŠÇ—Ì:
		return 0x04;
	case –ğE::‰œB’T‘è:
		return 0x08;
	case –ğE::¼‘’T‘è:
		return 0x10;
	case –ğE::‹ãB’T‘è:
		return 0x20;
	case –ğE::‰HB’T‘è:
		return 0x40;
	default:
		return 0;
	}
}

namespace ŠÖ” {




// ‘å–¼ID‚©‚ç³‹K‰»‚³‚ê‚½(0`7‚Ö‚ÆU‚è‚È‚¨‚³‚ê‚½)–ğEID‚ğ“¾‚é
int Get_‘å–¼–ğE(int ‘å–¼”Ô†y”z—ñ—pz) {

	// ”ÍˆÍƒ`ƒFƒbƒN
	if ( 0 <= ‘å–¼”Ô†y”z—ñ—pz && ‘å–¼”Ô†y”z—ñ—pz < Å‘å”::•«î•ñ::”z—ñ” ) { 

		switch ( p‘å–¼î•ñ[‘å–¼”Ô†y”z—ñ—pz]._–ğE) {
			case 0x01:
				return –ğE::ªˆÎ‘å«ŒR;
			case 0x02:
				return –ğE::ŠÇ—Ì;
			case 0x04:
				return –ğE::ŠÖ“ŒŠÇ—Ì;
			case 0x08 :
				return –ğE::‰œB’T‘è;
			case 0x10:
				return –ğE::¼‘’T‘è;
			case 0x20:
				return –ğE::‹ãB’T‘è;
			case 0x40:
				return –ğE::‰HB’T‘è;
			default:
				return 0;
		}
	}
	return 0;
}

// ŒR’cID‚©‚ç³‹K‰»‚³‚ê‚½–ğEID‚ğ“¾‚é
int Get_ŒR’c–ğE(int ŒR’c”Ô†y”z—ñ—pz) {

	// ”ÍˆÍƒ`ƒFƒbƒN
	if ( 0 <= ŒR’c”Ô†y”z—ñ—pz && ŒR’c”Ô†y”z—ñ—pz < Å‘å”::ŒR’cî•ñ::”z—ñ” ) { 

		// ‘å–¼©g‚È‚çA•Êˆ—
		if (pŒR’cî•ñ[ŒR’c”Ô†y”z—ñ—pz].ŒR’cŠ„“–”Ô† == 1) {
			int iDaimyoID = pŒR’cî•ñ[ŒR’c”Ô†y”z—ñ—pz].Š‘®‘å–¼y‘å–¼”Ô†z - 1;
			if (0 <= iDaimyoID && iDaimyoID < Å‘å”::‘å–¼î•ñ::”z—ñ”) {
				return Get_‘å–¼–ğE(iDaimyoID);
			}
		}

		return pŒR’cî•ñ[ŒR’c”Ô†y”z—ñ—pz]._–ğE;
	}
	ƒfƒoƒbƒOo—Í("w’è‚ÌŒR’c”Ô†y”z—ñ—pz‚Í”ÍˆÍŠO");
	return -1;
}


bool Set_‘å–¼–ğE(int iDaimyoID, int iYakusyokuValue) {
	if (0 <= iDaimyoID && iDaimyoID < Å‘å”::‘å–¼î•ñ::”z—ñ”) {

		if (–ğE::–³‚µ <= iYakusyokuValue && iYakusyokuValue <= –ğE::‰HB’T‘è) {

			int DenormalizeyakusyokuValue = DeNormalizeDaimyoYakusyokuValue(iYakusyokuValue);

			// ‘å–¼‚Å–Ú“I‚ÌID‚Ì–ğE‚ğ‚Á‚Ä‚¢‚él
			for (int iDID = 0; iDID < Å‘å”::‘å–¼î•ñ::”z—ñ”; iDID++) {
				int iDaimyoYakusyokuID = Get_‘å–¼–ğE(iDID);
				// ‚»‚Ì–ğE‚ğ‚Á‚Ä‚¢‚ê‚ÎA‚Í‚­’D
				if (iDaimyoYakusyokuID == iYakusyokuValue) {
					p‘å–¼î•ñ[iDID]._–ğE = 0;
				}
			}

			// ŒR’c‚Å–Ú“I‚ÌID‚Ì–ğE‚ğ‚Á‚Ä‚¢‚él
			for (int iGID = 0; iGID < Å‘å”::ŒR’cî•ñ::”z—ñ”; iGID++) {
				int iGundanYakusyokuID = Get_ŒR’c–ğE(iGID);
				// ‚»‚Ì–ğE‚ğ‚Á‚Ä‚¢‚ê‚ÎA‚Í‚­’D
				if (iGundanYakusyokuID == iYakusyokuValue) {
					pŒR’cî•ñ[iGID]._–ğE = 0;
				}
			}

			// ©•ª‚É‘ÎÛ‚Ì–ğE‚ğ‚Â‚¯‚éB
			p‘å–¼î•ñ[iDaimyoID]._–ğE = DenormalizeyakusyokuValue;

			return true;
		}
	}

	return false;
}


bool Set_ŒR’c–ğE(int iGundanID, int iYakusyokuValue) {

	if (0 <= iGundanID && iGundanID < Å‘å”::ŒR’cî•ñ::”z—ñ”) {

		// ‘å–¼©g‚È‚çA•Êˆ—
		if (pŒR’cî•ñ[iGundanID].ŒR’cŠ„“–”Ô† == 1) {
			int iDaimyoID = pŒR’cî•ñ[iGundanID].Š‘®‘å–¼y‘å–¼”Ô†z - 1;
			Set_‘å–¼–ğE(iDaimyoID, iYakusyokuValue);
		}

		if (–ğE::–³‚µ <= iYakusyokuValue && iYakusyokuValue <= –ğE::‰HB’T‘è) {

			// ‘å–¼‚Å–Ú“I‚ÌID‚Ì–ğE‚ğ‚Á‚Ä‚¢‚él
			for (int iDID = 0; iDID < Å‘å”::‘å–¼î•ñ::”z—ñ”; iDID++) {
				int iDaimyoYakusyokuID = Get_‘å–¼–ğE(iDID);
				// ‚»‚Ì–ğE‚ğ‚Á‚Ä‚¢‚ê‚ÎA‚Í‚­’D
				if (iDaimyoYakusyokuID == iYakusyokuValue) {
					p‘å–¼î•ñ[iDID]._–ğE = 0;
				}
			}

			// ŒR’c‚Å–Ú“I‚ÌID‚Ì–ğE‚ğ‚Á‚Ä‚¢‚él
			for (int iGID = 0; iGID < Å‘å”::ŒR’cî•ñ::”z—ñ”; iGID++) {
				int iGundanYakusyokuID = Get_ŒR’c–ğE(iGID);
				// ‚»‚Ì–ğE‚ğ‚Á‚Ä‚¢‚ê‚ÎA‚Í‚­’D
				if (iGundanYakusyokuID == iYakusyokuValue) {
					pŒR’cî•ñ[iGID]._–ğE = 0;
				}
			}

			// ©•ª‚É‘ÎÛ‚Ì–ğE‚ğ‚Â‚¯‚éB
			pŒR’cî•ñ[iGundanID]._–ğE = iYakusyokuValue;

			return true;
		}
	}

	return false;
}


}