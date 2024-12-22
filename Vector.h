#pragma once


namespace og {

	template<typename T>
	class Vector2 {

	public:
		T x{};
		T y{};

	public:
		Vector2() = default;

		Vector2(const T x, const T y) : x(x), y(y) { }

		inline Vector2<T> operator+(const Vector2<T>& other) {
			const Vector2 v{ this->x + other.x, this->y + other.y };
			return v;
		}

		inline Vector2<T> operator-(const Vector2<T>& other) {
			const Vector2 v{ this->x - other.x, this->y - other.y };
			return v;
		}

		inline void operator+=(const Vector2<T>& other) {
			this->x += other.x;
			this->y += other.y;
		}

		inline void operator-=(const Vector2<T>& other) {
			this->x -= other.x;
			this->y -= other.y;
		}

		inline bool operator==(const Vector2<T>& other) {
			return this->x == other.x && this->y == other.y;
		}

		inline bool operator!=(const Vector2<T>& other) {
			return this->x != other.x && this->y != other.y;
		}

		inline T dot(const Vector2<T>& other) {
			const T r = this->x * other.x + this->y * other.y;
			return r;
		}

		inline Vector2<T> cross(const Vector2<T>& other) {
			const Vector2<T> v{ this->x * other.y, -(this->y * other.x) };
			return v;
		}

	};

	template<typename T>
	class Vector3 {

	public:
		T x{};
		T y{};
		T z{};

	public:
		Vector3() = default;

		Vector3(const T x, const T y, const T z) : x(x), y(y), z(z) { }

		inline Vector3<T> operator+(const Vector3<T>& other) {
			const Vector3<T> v{ this->x + other.x, this->y + other.y, this->z + other.z };
			return v;
		}

		inline Vector3<T> operator-(const Vector3<T>& other) {
			const Vector3<T> v{ this->x - other.x, this->y - other.y, this->z - other.z };
			return v;
		}

		inline void operator+=(const Vector3<T>& other) {
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
		}

		inline void operator-=(const Vector3<T>& other) {
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
		}

		inline bool operator==(const Vector3<T>& other) {
			return this->x == other.x && this->y == other.y && this->z == other.z;
		}

		inline bool operator!=(const Vector3<T>& other) {
			return this->x != other.x || this->y != other.y || this->z != other.z;
		}

		inline T dot(const Vector3<T>& other) {
			const T r = this->x * other.x + this->y * other.y + this->Z * other.z;
			return r;
		}

		inline Vector3<T> cross(const Vector3<T>& other) {
			const Vector3<T> v{
				this->y * other.z - other.y * this->z,
				-(this->x * other.z - other.x * this->z),
				(this->x * other.y - other.x * this->y)
			};
			return v;
		}

	};

	typedef Vector2<int> Vector2i;
	typedef Vector2<float> Vector2f;
	typedef Vector2<double> Vector2d;

	typedef Vector3<int> Vector3i;
	typedef Vector3<float> Vector3f;
	typedef Vector3<double> Vector3d;

}