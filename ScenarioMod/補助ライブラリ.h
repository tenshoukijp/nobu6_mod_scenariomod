#pragma once

#include <cmath>
#include <vector>

using namespace std;

using �ԍ����X�g�^ = vector<int>;

/// <summary>
/// �Ώۂ̒l���l�̌ܓ����āA�����Ƃ���B
/// </summary>
/// <param name="value">�Ώۂ̕��������l</param>
/// <returns>�l�̌ܓ����ꂽ�����l</returns>
int round�s�������t(double value);


/// <summary>
/// �S�Ă̐��l��0.5�P�ʂ̖ڐ���ł���Ɖ��肵�āA�����ւƐ��l���ۂ߂�B
/// </summary>
/// <param name="value">�Ώۂ̕��������l</param>
/// <returns>0.5���݂ւƋz��(�l�̌ܓ��I�Ȋ��o)���ꂽ�����l</returns>
double round�s�񕪂̈�z�����t(double value);

