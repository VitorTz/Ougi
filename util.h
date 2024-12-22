#pragma once
#include <array>
#include <vector>


namespace og {


	int randint(int start, int end);

	template<typename T, std::size_t size>
	const T& choice(const std::array<T, size>& arr) {
		return arr[og::randint(0, size - 1)];
	}

	template<typename T>
	const T& choice(const std::vector<T>& vec) {
		return vec[og::randint(0, vec.size() - 1)];
	}

	template<typename T>
	const T* choice(T* arr, const std::size_t size) {
		return arr + og::randint(0, size - 1);
	}


}
