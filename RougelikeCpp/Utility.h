#pragma once
#include<vector>
#include<random>

int randomInt(int exclusiveMax);
int randomInt(int min, int inclusiveMax);
int sign(int value);


//백터 안의 값중 하나를 뽑는다.
template<typename T>
T pickOne(std::vector<T>& vector)
{
	return vector[randomInt(vector.size())];
}

//백터 안의 값의 순서를 섞어주는 함수, 카드덱 셔플을 생각하면 된다.
template<typename T>
void shuffle(std::vector<T>& vector)
{
	std::shuffle(vector.begin(), vector.end(), std::mt19937(std::random_device{}()));
}


