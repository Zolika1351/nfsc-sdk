namespace UMath
{
	inline float RecipSqrt(float x) { return 1.0f / sqrtf(x); }

	struct Vector3
	{
		float y, z, x;

		float Heading(void) const { return atan2(-x, y); }
		float Magnitude(void) const { return sqrt(x * x + y * y + z * z); }
		void Normalise(void)
		{
			float sq = MagnitudeSqr();
			if (sq > 0.0f)
			{
				float invsqrt = RecipSqrt(sq);
				x *= invsqrt;
				y *= invsqrt;
				z *= invsqrt;
			}
			else x = 1.0f;
		}
		float MagnitudeSqr(void) const { return x * x + y * y + z * z; }
		float Magnitude2D(void) const { return sqrtf(x * x + y * y); }
	};
	VALIDATE_SIZE(Vector3, 0xC);

	struct Quaternion
	{
		float y, z, x, w;
	};
	VALIDATE_SIZE(Quaternion, 0x10);

	inline Vector3 operator+(const Vector3& left, const Vector3& right)
	{
		Vector3 ret;
		ret.x = left.x + right.x;
		ret.y = left.y + right.y;
		ret.z = left.z + right.z;
		return ret;
	}
	
	inline Vector3 operator-(const Vector3& left, const Vector3& right)
	{
		Vector3 ret;
		ret.x = left.x - right.x;
		ret.y = left.y - right.y;
		ret.z = left.z - right.z;
		return ret;
	}

	inline Vector3 operator*(float left, const Vector3& right)
	{
		Vector3 ret;
		ret.x = left * right.x;
		ret.y = left * right.y;
		ret.z = left * right.z;
		return ret;
	}

	struct Matrix4
	{
		Vector3 right;						// 00-10
		uint32_t pad;

		Vector3 at;							// 10-20
		uint32_t pad2;

		Vector3 up;							// 20-30
		uint32_t pad3;

		Vector3 pos;						// 30-40
		uint32_t pad4;

		static inline Matrix4& kIdentity = *(Matrix4*)0x9D7880;

		void RotateX(float x)
		{
			float c = cos(x);
			float s = sin(x);

			float ry = right.y;
			float rz = right.z;
			float uy = up.y;
			float uz = up.z;
			float ay = at.y;
			float az = at.z;

			right.y = c * ry - s * rz;
			right.z = c * rz + s * ry;
			up.y = c * uy - s * uz;
			up.z = c * uz + s * uy;
			at.y = c * ay - s * az;
			at.z = c * az + s * ay;
		}

		void RotateY(float y)
		{
			float c = cos(y);
			float s = sin(y);

			float rx = right.x;
			float rz = right.z;
			float ux = up.x;
			float uz = up.z;
			float ax = at.x;
			float az = at.z;

			right.x = c * rx + s * rz;
			right.z = c * rz - s * rx;
			up.x = c * ux + s * uz;
			up.z = c * uz - s * ux;
			at.x = c * ax + s * az;
			at.z = c * az - s * ax;
		}

		void RotateZ(float z)
		{
			float c = cos(z);
			float s = sin(z);

			float ry = right.y;
			float rx = right.x;
			float uy = up.y;
			float ux = up.x;
			float ay = at.y;
			float ax = at.x;

			right.x = c * rx - s * ry;
			right.y = c * ry + s * rx;
			up.x = c * ux - s * uy;
			up.y = c * uy + s * ux;
			at.x = c * ax - s * ay;
			at.y = c * ay + s * ax;
		}

		void Rotate(float x, float y, float z)
		{
			float cX = cos(x);
			float sX = sin(x);
			float cY = cos(y);
			float sY = sin(y);
			float cZ = cos(z);
			float sZ = sin(z);

			float rx = right.x;
			float ry = right.y;
			float rz = right.z;
			float ux = up.x;
			float uy = up.y;
			float uz = up.z;
			float ax = at.x;
			float ay = at.y;
			float az = at.z;

			float x1 = cZ * cY - (sZ * sX) * sY;
			float x2 = (cZ * sX) * sY + sZ * cY;
			float x3 = -cX * sY;
			float y1 = -sZ * cX;
			float y2 = cZ * cX;
			float y3 = sX;
			float z1 = (sZ * sX) * cY + cZ * sY;
			float z2 = sZ * sY - (cZ * sX) * cY;
			float z3 = cX * cY;

			right.x = x1 * rx + y1 * ry + z1 * rz;
			right.y = x2 * rx + y2 * ry + z2 * rz;
			right.z = x3 * rx + y3 * ry + z3 * rz;
			up.x = x1 * ux + y1 * uy + z1 * uz;
			up.y = x2 * ux + y2 * uy + z2 * uz;
			up.z = x3 * ux + y3 * uy + z3 * uz;
			at.x = x1 * ax + y1 * ay + z1 * az;
			at.y = x2 * ax + y2 * ay + z2 * az;
			at.z = x3 * ax + y3 * ay + z3 * az;
		}
	};
	VALIDATE_SIZE(Matrix4, 0x40);
}

void VU0_quattom4(UMath::Quaternion* quat, UMath::Matrix4* mat)
{
	((void(__cdecl*)(UMath::Quaternion*, UMath::Matrix4*))0x605720)(quat, mat);
}

class bVector4
{
public:
	float x, z, y, w;

	float Magnitude(void) const { return sqrt(x * x + y * y + z * z); }
};
VALIDATE_SIZE(bVector4, 0x10);

class bMatrix4
{
public:
	bVector4 right;			// 00-10
	bVector4 up;			// 10-20
	bVector4 at;			// 20-30
	bVector4 pos;			// 30-40

	void Rotate(float x, float y, float z)
	{
		float cX = cos(x);
		float sX = sin(x);
		float cY = cos(y);
		float sY = sin(y);
		float cZ = cos(z);
		float sZ = sin(z);

		float rx = right.x;
		float ry = right.y;
		float rz = right.z;
		float ux = up.x;
		float uy = up.y;
		float uz = up.z;
		float ax = at.x;
		float ay = at.y;
		float az = at.z;

		float x1 = cZ * cY - (sZ * sX) * sY;
		float x2 = (cZ * sX) * sY + sZ * cY;
		float x3 = -cX * sY;
		float y1 = -sZ * cX;
		float y2 = cZ * cX;
		float y3 = sX;
		float z1 = (sZ * sX) * cY + cZ * sY;
		float z2 = sZ * sY - (cZ * sX) * cY;
		float z3 = cX * cY;

		right.x = x1 * rx + y1 * ry + z1 * rz;
		right.y = x2 * rx + y2 * ry + z2 * rz;
		right.z = x3 * rx + y3 * ry + z3 * rz;
		up.x = x1 * ux + y1 * uy + z1 * uz;
		up.y = x2 * ux + y2 * uy + z2 * uz;
		up.z = x3 * ux + y3 * uy + z3 * uz;
		at.x = x1 * ax + y1 * ay + z1 * az;
		at.y = x2 * ax + y2 * ay + z2 * az;
		at.z = x3 * ax + y3 * ay + z3 * az;
	}

	void RotateNew(float x, float y, float z);
};
VALIDATE_SIZE(bMatrix4, 0x40);