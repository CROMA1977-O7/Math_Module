#pragma once
//test
#if !defined(Math_Module)
#define Math_Module

#include <math.h>
#include <iostream>
#include <fstream>

#pragma once
using namespace std;

#define Deg2Rad (3.14159265358979323846 / 180.0)
#define Rad2Deg (180.0 / 3.14159265358979323846)
#define MATRIX_STACK_BUFFER_SIZE (32)

// 預先定義
template<typename Type>
class CMatrix2;
template<typename Type>
class CMatrix3;
template<typename Type>
class CMatrix4;
//////////////////////////////////////////////////////////////////////////
// 預先定義
template<typename Type>
class CVectorReference2;
template<typename Type>
class CVectorReference3;
template<typename Type>
class CVectorReference4;
template<typename Type>
class CVector2;
template<typename Type>
class CVector3;
template<typename Type>
class CVector4;

typedef  CVectorReference2<char>			CVectorReference2b;
typedef  CVectorReference2<unsigned char>	CVectorReference2ub;
typedef  CVectorReference2<int>				CVectorReference2i;
typedef  CVectorReference2<float>			CVectorReference2f;
typedef  CVectorReference2<double>			CVectorReference2d;
typedef  CVector2<char>						CVector2b;
typedef  CVector2<unsigned char>			CVector2ub;
typedef  CVector2<int>						CVector2i;
typedef  CVector2<float>					CVector2f;
typedef  CVector2<double>					CVector2d;

typedef  CVectorReference3<char>			CVectorReference3b;
typedef  CVectorReference3<unsigned char>	CVectorReference3ub;
typedef  CVectorReference3<int>				CVectorReference3i;
typedef  CVectorReference3<float>			CVectorReference3f;
typedef  CVectorReference3<double>			CVectorReference3d;
typedef  CVector3<char>						CVector3b;
typedef  CVector3<unsigned char>			CVector3ub;
typedef  CVector3<int>						CVector3i;
typedef  CVector3<float>					CVector3f;
typedef  CVector3<double>					CVector3d;

typedef  CMatrix2<float>					CMatrix2f;
typedef  CMatrix2<double>					CMatrix2d;
typedef  CMatrix3<float>					CMatrix3f;
typedef  CMatrix3<double>					CMatrix3d;
typedef  CMatrix4<float>					CMatrix4f;
typedef  CMatrix4<double>					CMatrix4d;
//////////////////////////////////////////////////////////////////////////
// Start Template
/// 二維的向量參考
template <typename Type>
class CVectorReference2 {
public:
										 // 定義各分量在不同用途時使用的名稱
		Type		 					 &m_x,&m_y; 				///< 在空間座標時使用的名稱
		Type							 &m_s,&m_t; 				///< 在材質座標時使用的名稱

										 /// 建構式
										 CVectorReference2(Type& Value0, Type& Value1);
										 /// 建構式
										 CVectorReference2(Type* Array);
										 /// 解構式
 virtual								~CVectorReference2();
										 /// 拷貝建構式 複製對方參考的對象
										 CVectorReference2(const CVectorReference2<Type> &Vector);

										 //////////////////////////////////////////////////////////////////////////

										 /// 設定向量
										 template<typename InputType>
			CVectorReference2<Type> &	 Set(const InputType x,const InputType y);						
										 /// 設定向量
										 template<typename InputType>
			CVectorReference2<Type> &	 Set(const InputType * Array);
										 /// 計算兩向量的 Dot
										 template<typename InputType>
			double						 Dot(const CVectorReference2<InputType> & Vector);
										 /// 使兩向量交換
										 template<typename InputType>
			void						 Swap(CVectorReference2<InputType> & Vector);
										 /// 取得向量的長度
			double						 GetLength(void);
										 /// 取得兩向量的角度 Ps. 當某一向量長度為 0 時則角度為 0
										 template<typename InputType>
			double						 GetAngle(const CVectorReference2<InputType> & Vector);
										 /// 取得兩向量的弳度 Ps. 當某一向量長度為 0 時則角度為 0
										 template<typename InputType>
			double						 GetRadian(const CVectorReference2<InputType> & Vector);
										 /// 取得單位化的向量
			CVector2<double> 			 GetNormalize(void);
										 /// 取得反轉的向量
			CVector2<double>			 GetReverse(void);
										 /// 使向量單位化
			CVectorReference2<Type> &	 Normalize(void);
										 /// 使向量反轉
			CVectorReference2<Type> &	 Reverse(void);
										 /// 檢查向量是否為零
			bool						 IsZero(void);								

			//////////////////////////////////////////////////////////////////////////

										 /// 覆載對向量的 + 運算子
										 template<typename InputType>
			CVector2<Type>				 operator+(const CVectorReference2<InputType> & Vector );
										 /// 覆載對向量的 - 運算子
										 template<typename InputType>
			CVector2<Type>				 operator-(const CVectorReference2<InputType> & Vector );
										 /// 覆載對實數的 * 運算子
			CVector2<Type>				 operator*(const double Value);
										 /// 覆載對向量的 * 運算子
										 template<typename InputType>
			CVector2<Type>				 operator*(const CVectorReference2<InputType> & Vector );
										 /// 覆載對實數的 / 運算子
			CVector2<Type>				 operator/(const double Value);
										 /// 覆載對向量的 / 運算子
										 template<typename InputType>
			CVector2<Type>				 operator/(const CVectorReference2<InputType> & Vector);
										 /// 覆載 = 運算子
			CVectorReference2<Type> &	 operator=(const CVectorReference2<float> & Vector);
										 /// 覆載 = 運算子
			CVectorReference2<Type>&	 operator=(const CVectorReference2<double>& Vector);
										 /// 覆載對向量的 += 運算子
										 template<typename InputType>
			CVectorReference2<Type>	&	 operator+=(const CVectorReference2<InputType> & Vector );
										 /// 覆載對向量的 -= 運算子
										 template<typename InputType>
			CVectorReference2<Type>	&	 operator-=(const CVectorReference2<InputType> & Vector );
										 /// 覆載對實數的 *= 運算子
			CVectorReference2<Type>	&	 operator*=(const double Value );
										 /// 覆載對向量的 *= 運算子
										 template<typename InputType>
			CVectorReference2<Type>	&	 operator*=(const CVectorReference2<InputType> & Vector);
										 /// 覆載對實數的 /= 運算子
			CVectorReference2<Type>	&	 operator/=(const double Value );
										 /// 覆載對向量的 /= 運算子
										 template<typename InputType>
			CVectorReference2<Type>	&	 operator/=(const CVectorReference2<InputType> & Vector);

			//////////////////////////////////////////////////////////////////////////

										 /// 覆載對向量的 == 運算子
										 template<typename InputType>
			bool						 operator==(const CVectorReference2<InputType> & Vector );
										 /// 覆載對向量的 != 運算子
										 template<typename InputType>
			bool						 operator!=(const CVectorReference2<InputType> & Vector );
										 /// 覆載對向量的 > 運算子
										 template<typename InputType>
			bool						 operator>(const CVectorReference2<InputType> & Vector );
										 /// 覆載對向量的 < 運算子
										 template<typename InputType>
			bool						 operator<(const CVectorReference2<InputType> & Vector );
										 /// 覆載對向量的 >= 運算子
										 template<typename InputType>
			bool						 operator>=(const CVectorReference2<InputType> & Vector );
										 /// 覆載對向量的 <= 運算子
										 template<typename InputType>
			bool						 operator<=(const CVectorReference2<InputType> & Vector );
protected:
										 /// 計算兩向量相加
										 template<typename InputType>
	inline	CVector2<Type>				 Add(const CVectorReference2<InputType> &Vector);
										 /// 計算兩向量相減
										 template<typename InputType>
	inline	CVector2<Type>				 Sub(const CVectorReference2<InputType> &Vector);
										 /// 計算向量對實數的乘法
	inline	CVector2<Type>				 Mul(const double Value);
										 /// 計算向量對向量的乘法
										 template<typename InputType>
	inline	CVector2<Type>				 Mul(const CVectorReference2<InputType> & Vector);
										 /// 計算向量對實數的除法
	inline	CVector2<Type>				 Div(const double Value);
										 /// 計算向量對向量的除法
										 template<typename InputType>
	inline	CVector2<Type>				 Div(const CVectorReference2<InputType> & Vector);
										 /// 使兩向量相等
										 template<typename InputType>
	inline	void						 Assign(const CVectorReference2<InputType> & Vector);
										 /// 計算兩向量相加並且儲存起來
										 template<typename InputType>
	inline	void						 AddAssign(const CVectorReference2<InputType> & Vector);
										 /// 計算兩向量相減並且儲存起來
										 template<typename InputType>
	inline	void						 SubAssign(const CVectorReference2<InputType> & Vector);
										 /// 計算向量對實數的乘法並且儲存起來
	inline	void						 MulAssign(const double Value);
										 /// 計算向量對向量的乘法並且儲存起來
										 template<typename InputType>
	inline	void						 MulAssign(const CVectorReference2<InputType> & Vector);
										 /// 計算向量對實數的除法並且儲存起來
	inline	void						 DivAssign(const double Value);
										 /// 計算向量對向量的除法並且儲存起來
										 template<typename InputType>
	inline	void						 DivAssign(const CVectorReference2<InputType> & Vector);
				//////////////////////////////////////////////////////////////////////////
										 /// 計算是否大於輸入向量
										 template<typename InputType>
	inline	bool						 Great(const CVectorReference2<InputType> &Vector);
										 /// 計算是否小於輸入向量
										 template<typename InputType>
	inline	bool						 Less(const CVectorReference2<InputType> &Vector);
										 /// 計算兩向量是否相等
										 template<typename InputType>
	inline	bool						 Equal(const CVectorReference2<InputType> &Vector);
										 /// 計算是否大於等於輸入向量
										 template<typename InputType>
	inline	bool						 GreatEqual(const CVectorReference2<InputType> &Vector);
										 /// 計算是否小於等於輸入向量
										 template<typename InputType>
	inline	bool						 LessEqual(const CVectorReference2<InputType> &Vector);
};


/// 二維的向量型態
template <typename Type>
class CVector2 :public CVectorReference2<Type> {
public:
			Type						 m_Buffer[2];									///< 資料空間

										 /// 預設的建構式
										 //CVector2();
										 /// 建構式
										 template<typename InputType>
										 CVector2(InputType Value0 = 0, InputType Value1 = 0);
										 /// 建構式
										 template<typename InputType>
										 CVector2(InputType* Array);
										 /// 解構式
	virtual								~CVector2();
										 /// 拷貝建構式										 
										 CVector2(const CVectorReference2<Type>& Vector);
										 /// 拷貝建構式										 
										 CVector2(const CVector2<Type>& Vector);

										 /// 拷貝建構式
			//							 template<typename InputType>
			//							 CVector2(const CVectorReference3<InputType> &Vector):
			//							 CVectorReference2<Type>(m_Buffer[0],m_Buffer[1])
			//							 {
			//								m_x = (Type)Vector.m_x;
			//								m_y = (Type)Vector.m_y;
			//							 }
			//							 /// 拷貝建構式
			//							 template<typename InputType>
			//							 CVector2(const CVectorReference4<InputType> &Vector):
			//							 CVectorReference2<Type>(m_Buffer[0],m_Buffer[1])
			//							 {
			//								m_x = (Type)Vector.m_x;
			//								m_y = (Type)Vector.m_y;
			//							 }
			//							 /// 拷貝建構式
			//							 template<typename InputType>
			//							 CVector2(const CVector2<InputType> &Vector):
			//							 CVectorReference2<Type>(m_Buffer[0],m_Buffer[1])
			//							 {
			//								m_x = (Type)Vector.m_x;
			//								m_y = (Type)Vector.m_y;
			//							 }
			//							 /// 拷貝建構式
			//							 template<typename InputType>
			//							 CVector2(const CVector3<InputType> &Vector):
			//							 CVectorReference2<Type>(m_Buffer[0],m_Buffer[1])
			//							 {
			//								m_x = (Type)Vector.m_x;
			//								m_y = (Type)Vector.m_y;
			//							 }
			//							 /// 拷貝建構式
			//							 template<typename InputType>
			//							 CVector2(const CVector4<InputType> &Vector):
			//							 CVectorReference2<Type>(m_Buffer[0],m_Buffer[1])
			//							 {
			//								m_x = (Type)Vector.m_x;
			//								m_y = (Type)Vector.m_y;
			//							 }

			////////////////////////////////////////////////////////////////////////////
/*
										 /// 覆載對向量的 + 運算子
										 template<typename InputType>
			CVector2<Type>				 operator+(const CVectorReference2<InputType> & Vector );
										 /// 覆載對向量的 - 運算子
										 template<typename InputType>
			CVector2<Type>				 operator-(const CVectorReference2<InputType> & Vector);
										 /// 覆載對實數的 * 運算子
			CVector2<Type>				 operator*(const double Value);
										 /// 覆載對向量的 * 運算子
										 template<typename InputType>
			CVector2<Type>				 operator*(const CVectorReference2<InputType> & Vector);
										 /// 覆載對實數的 / 運算子										 
			CVector2<Type>				 operator/(const double Value );
										 /// 覆載對向量的 / 運算子
										 template<typename InputType>
			CVector2<Type>				 operator/(const CVectorReference2<InputType> & Vector);
*/
										 /// 覆載 = 運算子										 
			CVectorReference2<Type>&	 operator=(const CVectorReference2<float> & Vector);
										 /// 覆載 = 運算子										 
			CVectorReference2<Type>&	 operator=(const CVectorReference2<double>& Vector);
/*
										 /// 覆載對向量的 += 運算子
										 template<typename InputType>
			CVectorReference2<Type>	&	 operator+=(const CVectorReference2<InputType> & Vector );
										 /// 覆載對向量的 -= 運算子
										 template<typename InputType>
			CVectorReference2<Type>	&	 operator-=(const CVectorReference2<InputType> & Vector );
										 /// 覆載對實數的 *= 運算子
			CVectorReference2<Type>	&	 operator*=(const double Value );
										 /// 覆載對向量的 *= 運算子
										 template<typename InputType>
			CVectorReference2<Type>	&	 operator*=(const CVectorReference2<InputType> & Vector);
										 /// 覆載對實數的 /= 運算子										
			CVectorReference2<Type>	&	 operator/=(const double Value );
										 /// 覆載對向量的 /= 運算子
										 template<typename InputType>
			CVectorReference2<Type>	&	 operator/=(const CVectorReference2<InputType> & Vector);

			////////////////////////////////////////////////////////////////////////////

										 /// 覆載對向量的 == 運算子
										 template<typename InputType>
			bool						 operator==(const CVectorReference2<InputType> & Vector );
										 /// 覆載對向量的 != 運算子
										 template<typename InputType>
			bool						 operator!=(const CVectorReference2<InputType> & Vector );
										 /// 覆載對向量的 > 運算子
										 template<typename InputType>
			bool						 operator>(const CVectorReference2<InputType> & Vector );
										 /// 覆載對向量的 < 運算子
										 template<typename InputType>
			bool						 operator<(const CVectorReference2<InputType> & Vector );
										 /// 覆載對向量的 >= 運算子
										 template<typename InputType>
			bool						 operator>=(const CVectorReference2<InputType> & Vector );
										 /// 覆載對向量的 <= 運算子
										 template<typename InputType>
			bool						 operator<=(const CVectorReference2<InputType> & Vector );
*/
};

//////////////////////////////////////////////////////////////////////////

/// 三維的向量參考
template <typename Type>
class CVectorReference3 {
public:
										 // 定義各分量在不同用途時使用的名稱
			Type		 				 &m_x,&m_y,&m_z;				///< 在空間座標時使用的名稱
			Type						 &m_s,&m_t,&m_p;				///< 在材質座標時使用的名稱
			Type						 &m_r,&m_g,&m_b;				///< 在顏色座標時使用的名稱

										 /// 建構式
										 CVectorReference3(Type& Value0, Type& Value1, Type& Value2);
										 /// 建構式
										 CVectorReference3(Type* Array);
										 /// 解構式
	virtual								~CVectorReference3() { }

										 /// 拷貝建構式 複製對方參考的對象
										 CVectorReference3(const CVectorReference3<Type> &Vector);
			//////////////////////////////////////////////////////////////////////////
										 /// 設定向量
										template<typename InputType>
			CVectorReference3<Type> &	Set(const InputType x, const InputType y, const InputType z);
										/// 設定向量
										template<typename InputType>
			CVectorReference3<Type> &	Set(const InputType * Array = nullptr);
										/// 計算兩向量的 Dot
										template<typename InputType>
			double						Dot(const CVectorReference3<InputType> & Vector);
										/// 計算兩向量的 Cross
										template<typename InputType>
			CVector3<Type>				Cross(const CVectorReference3<InputType> & Vector);
										/// 使兩向量交換
										template<typename InputType>
			void						Swap(CVectorReference3<InputType> & Vector);
										/// 取得向量的長度
			double						GetLength(void);
										/// 取得兩向量夾角的角度
										template<typename InputType>
			double						GetAngle(const CVectorReference3<InputType> & Vector);
										/// 取得兩向量夾角的弳度
										template<typename InputType>
			double						GetRadian(const CVectorReference3<InputType> & Vector);
										/// 取得單位化的向量
			CVector3<double>			GetNormalize(void);			
										/// 取得反轉的向量
			CVector3<double> 			GetReverse(void);		

			//////////////////////////////////////////////////////////////////////////

										/// 使向量單位化
			CVectorReference3<Type> &	Normalize(void);
										/// 使向量反轉
			CVectorReference3<Type> &	Reverse(void);
										/// 檢查向量是否為零
			bool						IsZero(void);

			//////////////////////////////////////////////////////////////////////////

										 /// 覆載對向量的 + 運算子
										 template<typename InputType>
			CVector3<Type>				 operator+(const CVectorReference3<InputType> & Vector );
										 /// 覆載對向量的 - 運算子
										 template<typename InputType>
			CVector3<Type>				 operator-(const CVectorReference3<InputType> & Vector );

										 /// 覆載對實數的 * 運算子
			CVector3<Type>				 operator*(const double Value );

										 /// 覆載對向量的 * 運算子
										 template<typename InputType>
			CVector3<Type>				 operator*(const CVectorReference3<InputType> & Vector );
										 /// 覆載對實數的 / 運算子
			CVector3<Type>				 operator/(const double Value);
										 /// 覆載對向量的 / 運算子
										 template<typename InputType>
			CVector3<Type>				 operator/(const CVectorReference3<InputType> & Vector);
										 /// 覆載向量的外積運算子
										 template<typename InputType>
			CVector3<Type>				 operator^(const CVectorReference3<InputType>  & Vector );
										 /// 覆載 = 運算子										 
			CVectorReference3<Type> &	 operator=(const CVectorReference3<float> & Vector);
										 /// 覆載 = 運算子										 
			CVectorReference3<Type> &	 operator=(const CVectorReference3<double> & Vector);
										 /// 覆載對向量的 += 運算子
										 template<typename InputType>
			CVectorReference3<Type>	&	 operator+=(const CVectorReference3<InputType> & Vector );
										 /// 覆載對向量的 -= 運算子
										 template<typename InputType>
			CVectorReference3<Type>	&	 operator-=(const CVectorReference3<InputType> & Vector );
										 /// 覆載對實數的 *= 運算子
			CVectorReference3<Type>	&	 operator*=(const double Value );
										 /// 覆載對向量的 *= 運算子
										 template<typename InputType>
			CVectorReference3<Type>	&	 operator*=(const CVectorReference3<InputType> & Vector);
										 /// 覆載對實數的 /= 運算子										 
			CVectorReference3<Type>	&	 operator/=(const double Value );
										 /// 覆載對向量的 /= 運算子
										 template<typename InputType>
			CVectorReference3<Type>	&	 operator/=(const CVectorReference3<InputType> & Vector);

			//////////////////////////////////////////////////////////////////////////

										 /// 覆載對向量的 == 運算子
										 template<typename InputType>
			bool						 operator==(const CVectorReference3<InputType> & Vector );
										 /// 覆載對向量的 != 運算子
										 template<typename InputType>
			bool						 operator!=(const CVectorReference3<InputType> & Vector );
										 /// 覆載對向量的 > 運算子
										 template<typename InputType>
			bool						 operator>(const CVectorReference3<InputType> & Vector );
										 /// 覆載對向量的 < 運算子
										 template<typename InputType>
			bool						 operator<(const CVectorReference3<InputType> & Vector );
										 /// 覆載對向量的 >= 運算子
										 template<typename InputType>
			bool						 operator>=(const CVectorReference3<InputType> & Vector );
										 /// 覆載對向量的 <= 運算子
										 template<typename InputType>
			bool						 operator<=(const CVectorReference3<InputType> & Vector );
protected:
										 /// 計算兩向量相加
										 template<typename InputType>
	inline	CVector3<Type>				 Add(const CVectorReference3<InputType> &Vector);
										 /// 計算兩向量相減
										 template<typename InputType>
	inline	CVector3<Type>				 Sub(const CVectorReference3<InputType> &Vector);
										 /// 計算向量對實數的乘法
	inline	CVector3<Type>				 Mul(const double Value);
										 /// 計算向量對向量的乘法
										 template<typename InputType>
	inline	CVector3<Type>				 Mul(const CVectorReference3<InputType> & Vector);
										 /// 計算向量對實數的除法
	inline	CVector3<Type>				 Div(const double Value);
										 /// 計算向量對向量的除法
										 template<typename InputType>
	inline	CVector3<Type>				 Div(const CVectorReference3<InputType> & Vector);
										 /// 使兩向量相等
										 template<typename InputType>
	inline	void						 Assign(const CVectorReference3<InputType> & Vector);
										 /// 計算兩向量相加並且儲存起來
										 template<typename InputType>
	inline	void						 AddAssign(const CVectorReference3<InputType> & Vector);
										 /// 計算兩向量相減並且儲存起來
										 template<typename InputType>
	inline	void						 SubAssign(const CVectorReference3<InputType> & Vector);
										 /// 計算向量對實數的乘法並且儲存起來
	inline	void						 MulAssign(const double Value);
										 /// 計算向量對向量的乘法並且儲存起來
										 template<typename InputType>
	inline	void						 MulAssign(const CVectorReference3<InputType> & Vector);
										 /// 計算向量對實數的除法並且儲存起來										 
	inline	void						 DivAssign(const double Value);
										 /// 計算向量對向量的除法並且儲存起來
										 template<typename InputType>
	inline	void						 DivAssign(const CVectorReference3<InputType> & Vector);

			//////////////////////////////////////////////////////////////////////////

										 /// 計算是否大於輸入向量
										 template<typename InputType>
	inline	bool						 Great(const CVectorReference3<InputType> &Vector);
										 /// 計算是否小於輸入向量
										 template<typename InputType>
	inline	bool						 Less(const CVectorReference3<InputType> &Vector);
										 /// 計算兩向量是否相等
										 template<typename InputType>
	inline	bool						 Equal(const CVectorReference3<InputType> &Vector);
										 /// 計算是否大於等於輸入向量
										 template<typename InputType>
	inline	bool						 GreatEqual(const CVectorReference3<InputType> &Vector);
										 /// 計算是否小於等於輸入向量
										 template<typename InputType>
	inline	bool						 LessEqual(const CVectorReference3<InputType> &Vector);
};

//////////////////////////////////////////////////////////////////////////

/// 三維的向量型態
template <typename Type>
class CVector3 :public CVectorReference3<Type> {
public:

			Type						 m_Buffer[3];									///< 資料空間
										 /// 預設的建構式
										 CVector3();
										 /// 建構式
										 template<typename InputType>
										 CVector3(InputType Value0, InputType Value1, InputType Value2);
										 /// 建構式
										 template<typename InputType>
										 CVector3(InputType* Array);
										 /// 建構式
										 CVector3(const CVectorReference2<Type>& Vector, Type z = 0);
										 /// 建構式
										 CVector3(const CVector2<Type>& Vector, Type z = 0); 
										 /// 解構式
	virtual								~CVector3(){ }
		
										 /// 拷貝建構式
										 CVector3(const CVectorReference3<Type> &Vector);
										 /// 拷貝建構式
										 CVector3(const CVector3<Type>& Vector);
										 ///// 拷貝建構式
										 //template<typename InputType>
										 //CVector3(const CVectorReference4<InputType> &Vector):
										 //CVectorReference3<Type>(m_Buffer[0],m_Buffer[1],m_Buffer[2])
										 //{
											//m_x = (Type)Vector.m_x;
											//m_y = (Type)Vector.m_y;
											//m_z = (Type)Vector.m_z;
										 //}
										 ///// 拷貝建構式
										 //template<typename InputType>
										 //CVector3(const CVector2<InputType> &Vector, InputType z):
										 //CVectorReference3<Type>(m_Buffer[0],m_Buffer[1],m_Buffer[2])
										 //{
											//m_x = (Type)Vector.m_x;
											//m_y = (Type)Vector.m_y;
											//m_z = (Type)z;
										 //}

										 ///// 拷貝建構式
										 //template<typename InputType>
										 //CVector3(const CVector3<InputType> &Vector):
										 //CVectorReference3<Type>(m_Buffer[0],m_Buffer[1],m_Buffer[2])
										 //{
											//m_x = (Type)Vector.m_x;
											//m_y = (Type)Vector.m_y;
											//m_z = (Type)Vector.m_z;
										 //}

										 ///// 拷貝建構式
										 //template<typename InputType>
										 //CVector3(const CVector4<InputType> &Vector):
										 //CVectorReference3<Type>(m_Buffer[0],m_Buffer[1],m_Buffer[2])
										 //{
											//m_x = (Type)Vector.m_x;
											//m_y = (Type)Vector.m_y;
											//m_z = (Type)Vector.m_z;
										 //}

			//////////////////////////////////////////////////////////////////////////
/*
										 /// 覆載對向量的 + 運算子
										 template<typename InputType>
			CVector3<Type>				 operator+(const CVectorReference3<InputType> & Vector );
										 /// 覆載對向量的 - 運算子
										 template<typename InputType>
			CVector3<Type>				 operator-(const CVectorReference3<InputType> & Vector );
										 /// 覆載對實數的 * 運算子
			CVector3<Type>				 operator*(const double Value );
										 /// 覆載對向量的 * 運算子
										 template<typename InputType>
			CVector3<Type>				 operator*(const CVectorReference3<InputType> & Vector );
										 /// 覆載對實數的 / 運算子										 
			CVector3<Type>				 operator/(const double Value );
										 /// 覆載對向量的 / 運算子
										 template<typename InputType>
			CVector3<Type>				 operator/(const CVectorReference3<InputType> & Vector);
*/
										 /// 覆載 = 運算子									 
			CVectorReference3<Type> &	 operator=(const CVectorReference3<float> & Vector);
										 /// 覆載 = 運算子									 
			CVectorReference3<Type> &	 operator=(const CVectorReference3<double> & Vector);
/*
										 /// 覆載對向量的 += 運算子
										 template<typename InputType>
			CVectorReference3<Type>	&	 operator+=(const CVectorReference3<InputType> & Vector );
										 /// 覆載對向量的 -= 運算子
										 template<typename InputType>
			CVectorReference3<Type>	&	 operator-=(const CVectorReference3<InputType> & Vector );
										 /// 覆載對實數的 *= 運算子
			CVectorReference3<Type>	&	 operator*=(const double Value );
										 /// 覆載對向量的 *= 運算子
										 template<typename InputType>
			CVectorReference3<Type>	&	 operator*=(const CVectorReference3<InputType> & Vector);
										 /// 覆載對實數的 /= 運算子										 
			CVectorReference3<Type>	&	 operator/=(const double Value );
										 /// 覆載對向量的 /= 運算子
										 template<typename InputType>
			CVectorReference3<Type>	&	 operator/=(const CVectorReference3<InputType> & Vector);

			//////////////////////////////////////////////////////////////////////////

										 /// 覆載對向量的 == 運算子
										 template<typename InputType>
			bool						 operator==(const CVectorReference3<InputType> & Vector );

										 /// 覆載對向量的 != 運算子
										 template<typename InputType>
			bool						 operator!=(const CVectorReference3<InputType> & Vector );
										 /// 覆載對向量的 > 運算子
										 template<typename InputType>
			bool						 operator>(const CVectorReference3<InputType> & Vector );
										 /// 覆載對向量的 < 運算子
										 template<typename InputType>
			bool						 operator<(const CVectorReference3<InputType> & Vector );
										 /// 覆載對向量的 >= 運算子
										 template<typename InputType>
			bool						 operator>=(const CVectorReference3<InputType> & Vector );
										 /// 覆載對向量的 <= 運算子
										 template<typename InputType>
			bool						 operator<=(const CVectorReference3<InputType> & Vector );
*/
};

//////////////////////////////////////////////////////////////////////////

/// 四維的向量參考
template <typename Type>
class CVectorReference4 {
public:

										 // 定義各分量在不同用途時使用的名稱
			Type		 				 &m_x, &m_y, &m_z, &m_w; 			///< 在空間座標時使用的名稱
			Type						 &m_s, &m_t, &m_p, &m_q; 			///< 在材質座標時使用的名稱
			Type						 &m_r, &m_g, &m_b, &m_a; 			///< 在顏色座標時使用的名稱
	
										 /// 建構式
										 CVectorReference4(Type &Value0, Type &Value1, Type &Value2, Type &Value3):
										 m_x(Value0),m_y(Value1),m_z(Value2),m_w(Value3),
										 m_s(Value0),m_t(Value1),m_p(Value2),m_q(Value3),
										 m_r(Value0),m_g(Value1),m_b(Value2),m_a(Value3)
										 {
										 }
										 /// 建構式
										 CVectorReference4(Type * Array):
										 m_x(Array[0]),m_y(Array[1]),m_z(Array[2]),m_w(Array[3]),
										 m_s(Array[0]),m_t(Array[1]),m_p(Array[2]),m_q(Array[3]),
										 m_r(Array[0]),m_g(Array[1]),m_b(Array[2]),m_a(Array[3])
										 {
										 }
										 /// 解構式
	virtual								~CVectorReference4(){
										 }
										 /// 拷貝建構式 複製對方參考的對象
										 CVectorReference4(const CVectorReference4<Type> &Vector):
										 m_x(Vector.m_x),m_y(Vector.m_y),m_z(Vector.m_z),m_w(Vector.m_w),
										 m_s(Vector.m_s),m_t(Vector.m_t),m_p(Vector.m_p),m_q(Vector.m_p),
										 m_r(Vector.m_r),m_g(Vector.m_g),m_b(Vector.m_b),m_a(Vector.m_a)
										 {
										 }

			//////////////////////////////////////////////////////////////////////////
										 /// 設定向量
										 template<typename InputType>
			CVectorReference4<Type> &	 Set(const InputType x, const InputType y, const InputType z, const InputType w)
										 {
											m_x = (Type) x; m_y = (Type) y; m_z = (Type) z; m_w = (Type) w;
											return *this;
										 }
										 /// 設定向量
										 template<typename InputType>
			CVectorReference4<Type> &	 Set(const InputType * Array)
										 {
											m_x = (Type) Array[0]; m_y = (Type) Array[1]; m_z = (Type) Array[2]; m_w = (Type) Array[3];
											return *this;
										 }
										 /// 計算兩向量的 Dot ???
										 template<typename InputType>
			double						 Dot(const CVectorReference4<InputType> & Vector)
										 {
											return (double)m_x * Vector.m_x + m_y * Vector.m_y + m_z * Vector.m_z + m_w * Vector.m_w;
										 }
										 /// 計算兩向量的 Cross ???
										 template<typename InputType>
			CVector4<Type>				 Cross(const CVectorReference4<InputType> & Vector)
										 {
											double X,Y,Z;
											// 計算結果
											X = (double)m_y * Vector.m_z - m_z * Vector.m_y;
											Y = (double)m_z * Vector.m_x - m_x * Vector.m_z;
											Z = (double)m_x * Vector.m_y - m_y * Vector.m_x;

											return CVector4<Type>(X, Y, Z, (Type)1);
										 }
										 /// 使兩向量交換
										 template<typename InputType>
			void						 Swap(CVectorReference4<InputType> & Vector)
										 {
											 // 複製 Vector 的值
											CVector4<double> Temp;
											Temp = Vector;
											 Vector = *this;
											 *this	= Temp;
										 }
										 /// 取得兩向量的角度
										 template<typename InputType>
			double						 GetAngle(const CVectorReference4<InputType> & Vector)
										 {
											double Length1 = (*this).GetLength();
											double Length2 = Vector.GetLength();
											double Length  = Length1 * Length2;
											if(Length == 0)
												return 0;
											double Cos = max( -1, min( 1, (*this).Dot(Vector) / Length ) );
											return acos( Cos ) * 180 / 3.1415926f;
										 }
										/// 取得兩向量的弳度
										template<typename InputType>
			double						GetRadian(const CVectorReference4<InputType> & Vector)
										{
											double Length1 = (*this).GetLength();
											double Length2 = Vector.GetLength();
											double Length  = Length1 * Length2;
											if(Length == 0)
												return 0;
											double Cos = max( -1, min( 1, (*this).Dot(Vector) / Length ) );
											return acos( Cos ) * 180 / 3.1415926f;
										}

										/// 取得向量的長度
			double						GetLength(void)
										{
											double Size = (double)m_x*m_x+m_y*m_y+m_z*m_z;
											return sqrt(Size);
										}

			//////////////////////////////////////////////////////////////////////////
										 /// 取得單位化的向量
			CVector4<Type> 				 GetNormalize(void)
										{
											double Length = GetLength();
											if(Length == 0)
												return CVector4<Type>(*this);
											return CVector4<Type>( (Type) (m_x / Length), (Type) (m_y / Length),(Type) (m_z / Length), (Type)(m_w / Length));
										 }
										 /// 取得反轉的向量
			CVector4<Type> 				 GetReverse(void)
										{
											return CVector4<Type>(-m_x,-m_y,-m_z,-m_w);
										 }
			//////////////////////////////////////////////////////////////////////////
										 /// 使向量單位化
			CVectorReference4<Type> &	 Normalize(void)
										{
											double Length = GetLength();
											if(Length == 0)
												return * this;
											m_x = (Type)(m_x / Length);
											m_y = (Type)(m_y / Length);
											m_z = (Type)(m_z / Length);
											return *this;
										 }
										 /// 使向量反轉
			CVectorReference4<Type> &	 Reverse(void)
										{
											m_x = - m_x;
											m_y = - m_y;
											m_z = - m_z;
											m_w = - m_w;
											return *this;
										 }
										 /// 檢查向量是否為零
			bool						 IsZero(void)
										{
											double LengthPow2 = m_x * m_x + m_y * m_y + m_z * m_z + m_w * m_w;
											if(LengthPow2 > 0.000001)
												return false;
											return true;
										}
			//////////////////////////////////////////////////////////////////////////
										 /// 覆載對向量的 + 運算子
										 template<typename InputType>
			CVector4<Type>				 operator+(const CVectorReference4<InputType> & Vector )
										 {
											return Add(Vector);
										 }
										 /// 覆載對向量的 - 運算子
										 template<typename InputType>
			CVector4<Type>				 operator-(const CVectorReference4<InputType> & Vector )
										 {
											return Sub(Vector);
										 }
										 /// 覆載對實數的 * 運算子
			CVector4<Type>				 operator*(const double Value )
										{
											return Mul(Value);
										 }
										 /// 覆載對向量的 * 運算子
										 template<typename InputType>
			CVector4<Type>				 operator*(const CVectorReference4<InputType> & Vector )
										 {
											return Mul(Vector);
										 }

										 /// 覆載對實數的 / 運算子										
			CVector4<Type>				 operator/(const double Value )
										 {
											return Div(Value);
										 }
										 /// 覆載對向量的 / 運算子
										 template<typename InputType>
			CVector4<Type>				 operator/(const CVectorReference4<InputType> & Vector)
										 {
											 return Div(Vector);
										 }

										 /// 覆載向量的外積運算子
										 template<typename InputType>
			CVector4<Type>				 operator^(const CVectorReference4<InputType>  & Vector )
										 {
											return Cross(Vector);
										 }
										 /// 覆載 = 運算子
										 template<typename InputType>
	inline	CVectorReference4<Type> &	 operator=(const CVectorReference4<InputType> & Vector)
										 {
											Assign(Vector);
											return *this;
										 }
										 /// 覆載對向量的 += 運算子
										 template<typename InputType>
	inline	CVectorReference4<Type>	&	 operator+=(const CVectorReference4<InputType> & Vector )
										 {
											AddAssign(Vector);
											return *this;
										 }
										 /// 覆載對向量的 -= 運算子
										 template<typename InputType>
	inline	CVectorReference4<Type>	&	 operator-=(const CVectorReference4<InputType> & Vector )
										 {
											SubAssign(Vector);
											return *this;
										 }
										 /// 覆載對實數的 *= 運算子
	inline	CVectorReference4<Type>	&	 operator*=(const double Value )
										{
											MulAssign(Value);
											return *this;
										 }
										 /// 覆載對向量的 *= 運算子
										 template<typename InputType>
	inline	CVectorReference4<Type>	&	 operator*=(const CVectorReference4<InputType> & Vector)
										 {
											MulAssign(Vector);
											return *this;
										 }
										 /// 覆載對實數的 /= 運算子										
	inline	CVectorReference4<Type>	&	 operator/=(const double Value )
										 {
											DivAssign(Value);
											return *this;
										 }
										 /// 覆載對向量的 /= 運算子
										 template<typename InputType>
	inline	CVectorReference4<Type>	&	 operator/=(const CVectorReference4<InputType> & Vector)
										 {
											 DivAssign(Vector);
											 return *this;
										 }

			//////////////////////////////////////////////////////////////////////////
										 /// 覆載對向量的 == 運算子
										 template<typename InputType>
	inline	bool						 operator==(const CVectorReference4<InputType> & Vector )
										 {
											return Equal(Vector);
										 }
										 /// 覆載對向量的 != 運算子
										 template<typename InputType>
	inline	bool						 operator!=(const CVectorReference4<InputType> & Vector )
										 {
											return !Equal(Vector);
										 }
										 /// 覆載對向量的 > 運算子
										 template<typename InputType>
	inline	bool						 operator>(const CVectorReference4<InputType> & Vector )
										 {
											return Great(Vector);
										 }
										 /// 覆載對向量的 < 運算子
										 template<typename InputType>
	inline	bool						 operator<(const CVectorReference4<InputType> & Vector )
										 {
											return Less(Vector);
										 }
										 /// 覆載對向量的 >= 運算子
										 template<typename InputType>
	inline	bool						 operator>=(const CVectorReference4<InputType> & Vector )
										 {
											return GreatEqual(Vector);
										 }
										 /// 覆載對向量的 <= 運算子
										 template<typename InputType>
	inline	bool						 operator<=(const CVectorReference4<InputType> & Vector )
										 {
											return LessEqual(Vector);
										 }

protected:
										 /// 計算兩向量相加
										 template<typename InputType>
	inline	CVector4<Type>				 Add(const CVectorReference4<InputType> &Vector)
										 {
											 return CVector4<Type>((Type)(m_x + Vector.m_x),(Type)(m_y + Vector.m_y),(Type)(m_z + Vector.m_z),(Type)(m_w + Vector.m_w));
										 }
										 /// 計算兩向量相減
										 template<typename InputType>
	inline	CVector4<Type>				 Sub(const CVectorReference4<InputType> &Vector)
										 {
											 return CVector4<Type>((Type)(m_x - Vector.m_x),(Type)(m_y - Vector.m_y),(Type)(m_z - Vector.m_z),(Type)(m_w - Vector.m_w));
										 }
										 /// 計算向量對實數的乘法
	inline	CVector4<Type>				 Mul(const double Value)
										{
											return CVector4<Type>((Type)(m_x * Value),(Type)(m_y * Value),(Type)(m_z * Value),(Type)(m_w * Value));
										 }
										 /// 計算向量對向量的乘法
										 template<typename InputType>
	inline	CVector4<Type>				 Mul(const CVectorReference4<InputType> & Vector)
										 {
											return CVector4<Type>((Type)(m_x * Vector.m_x),(Type)(m_y * Vector.m_y),(Type)(m_z * Vector.m_z),(Type)(m_w * Vector.m_w));
										 }
										 /// 計算向量對實數的除法										 
	inline	CVector4<Type>				 Div(const double Value)
										 {
											if(Value == 0)
												return CVector4<Type>(*this);
											return CVector4<Type>((Type)(m_x / Value),(Type)(m_y / Value),(Type)(m_z / Value),(Type)(m_w / Value));
										 }
										 /// 計算向量對向量的除法
										 template<typename InputType>
	inline	CVector4<Type>				 Div(const CVectorReference4<InputType> & Vector)
										 {
											if(Vector.IsZero() == true)
												return CVector4<Type>(*this);
											return CVector4<Type>((Type)(m_x / Vector.m_x),(Type)(m_y / Vector.m_y),(Type)(m_z / Vector.m_z),(Type)(m_w / Vector.m_w));
										 }

										 /// 使兩向量相等
										 template<typename InputType>
	inline	void						 Assign(const CVectorReference4<InputType> & Vector)
										 {
											 m_x = (Type)Vector.m_x;
											 m_y = (Type)Vector.m_y;
											 m_z = (Type)Vector.m_z;
											 m_w = (Type)Vector.m_w;
										 }
										 /// 計算兩向量相加並且儲存起來
										 template<typename InputType>
	inline	void						 AddAssign(const CVectorReference4<InputType> & Vector)
										 {
											 m_x = (Type)(m_x + Vector.m_x);
											 m_y = (Type)(m_y + Vector.m_y);
											 m_z = (Type)(m_z + Vector.m_z);
											 m_w = (Type)(m_w + Vector.m_w);
										 }
										 /// 計算兩向量相減並且儲存起來
										 template<typename InputType>
	inline	void						 SubAssign(const CVectorReference4<InputType> & Vector)
										 {
											 m_x = (Type)(m_x - Vector.m_x);
											 m_y = (Type)(m_y - Vector.m_y);
											 m_z = (Type)(m_z - Vector.m_z);
											 m_w = (Type)(m_w - Vector.m_w);
										 }
										 /// 計算向量對實數的乘法並且儲存起來
	inline	void						 MulAssign(const double Value)
										{
											 m_x = (Type)(m_x * Value);
											 m_y = (Type)(m_y * Value);
											 m_z = (Type)(m_z * Value);
											 m_w = (Type)(m_w * Value);
										 }
										 /// 計算向量對向量的乘法並且儲存起來
										 template<typename InputType>
	inline	void						 MulAssign(const CVectorReference4<InputType> & Vector)
										 {
											 m_x = (Type)(m_x * Vector.m_x);
											 m_y = (Type)(m_y * Vector.m_y);
											 m_z = (Type)(m_z * Vector.m_z);
											 m_w = (Type)(m_w * Vector.m_w);
										 }

										 /// 計算向量對實數的除法並且儲存起來										
	inline	void						 DivAssign(const double Value)
										 {
											if(Value == 0)
												return ;
											m_x = (Type)(m_x / Value);
											m_y = (Type)(m_y / Value);
											m_z = (Type)(m_z / Value);
											m_w = (Type)(m_w / Value);
										 }
										 /// 計算向量對向量的除法並且儲存起來
										 template<typename InputType>
	inline	void						 DivAssign(const CVectorReference4<InputType> & Vector)
										 {
											if(Vector.IsZero() == true)
												return;
											 m_x = (Type)(m_x / Vector.m_x);
											 m_y = (Type)(m_y / Vector.m_y);
											 m_z = (Type)(m_z / Vector.m_z);
											 m_w = (Type)(m_w / Vector.m_w);
										 }

			//////////////////////////////////////////////////////////////////////////
										 /// 計算是否大於輸入向量???
										 template<typename InputType>
	inline	bool						 Great(const CVectorReference4<InputType> &Vector)
										 {
											 if(m_x > Vector.m_x && m_y > Vector.m_y && m_z > Vector.m_z && m_w > Vector.m_w)
												return true;
											return false;
										 }
										 /// 計算是否小於輸入向量
										 template<typename InputType>
	inline	bool						 Less(const CVectorReference4<InputType> &Vector)
										 {
											 if(m_x > Vector.m_x && m_y > Vector.m_y && m_z > Vector.m_z && m_w > Vector.m_w)
												return false;
											return true;
										 }
										 /// 計算兩向量是否相等
										 template<typename InputType>
	inline	bool						 Equal(const CVectorReference4<InputType> &Vector)
										 {
											CVector4<Type> Temp( (*this) - Vector);
											double LengthPow2 = Temp.m_x * Temp.m_x + Temp.m_y * Temp.m_y + Temp.m_z * Temp.m_z + Temp.m_w * Temp.m_w;
											if(LengthPow2 > 0.000001)
												return false;
											return true;
										 }
										 /// 計算是否大於等於輸入向量
										 template<typename InputType>
	inline	bool						 GreatEqual(const CVectorReference4<InputType> &Vector)
										 {
											 if(m_x >= Vector.m_x && m_y >= Vector.m_y && m_z >= Vector.m_z && m_w >= Vector.m_w)
												return true;
											return false;
										 }
										 /// 計算是否小於等於輸入向量
										 template<typename InputType>
	inline	bool						 LessEqual(const CVectorReference4<InputType> &Vector)
										 {
											 if(m_x >= Vector.m_x && m_y >= Vector.m_y && m_z >= Vector.m_z && m_w >= Vector.m_w)
												return false;
											return true;
										 }
};


//////////////////////////////////////////////////////////////////////////

/// 四維的向量型態
template <typename Type>
class CVector4 :public CVectorReference4<Type>
{
public:

			Type						 m_Buffer[4];									///< 資料空間

										 /// 預設的建構式
										 CVector4():
										 CVectorReference4<Type>(m_Buffer[0],m_Buffer[1],m_Buffer[2],m_Buffer[3])
										 {
											m_Buffer[0] = 0; m_Buffer[1] = 0; m_Buffer[2] = 0; m_Buffer[3] = 1;
										 }
										 /// 建構式
										 template<typename InputType>
										 CVector4(const InputType Value0, const InputType Value1, const InputType Value2, const InputType Value3):
										 CVectorReference4<Type>(m_Buffer[0],m_Buffer[1],m_Buffer[2],m_Buffer[3])
										 {
											m_Buffer[0] = (Type)Value0; m_Buffer[1] = (Type)Value1;	m_Buffer[2] = (Type)Value2; m_Buffer[3] = (Type)Value3;
										 }

										 /// 建構式
										 template<typename InputType>
										 CVector4(const InputType * Array):
										 CVectorReference4<Type>(m_Buffer[0],m_Buffer[1],m_Buffer[2],m_Buffer[3])
										 {
											 if(Array == nullptr){
												m_Buffer[0] = 0; m_Buffer[1] = 0; m_Buffer[2] = 0; m_Buffer[3] = 1;
											 }else{
												m_Buffer[0] = (Type)Array[0]; 
												m_Buffer[1] = (Type)Array[1];
												m_Buffer[2] = (Type)Array[2];
												m_Buffer[3] = (Type)Array[3];
											 }
										 }
										 /// 解構式
	virtual								~CVector4(){}
/*
										 /// 拷貝建構式
										 template<typename InputType>
										 CVector4(const CVectorReference2<InputType> &Vector, InputType z, InputType w):
										 CVectorReference4<Type>(m_Buffer[0],m_Buffer[1],m_Buffer[2],m_Buffer[3])
										 {
											m_x = (Type)Vector.m_x;
											m_y = (Type)Vector.m_y;
											m_z = (Type)z;
											m_w = (Type)w;
										 }
										 /// 拷貝建構式
										 template<typename InputType>
										 CVector4(const CVectorReference3<InputType> &Vector, InputType w = 1):
										 CVectorReference4<Type>(m_Buffer[0],m_Buffer[1],m_Buffer[2],m_Buffer[3])
										 {
											m_x = (Type)Vector.m_x;
											m_y = (Type)Vector.m_y;
											m_z = (Type)Vector.m_z;
											m_w = (Type)w;
										 }
										 /// 拷貝建構式
										 template<typename InputType>
										 CVector4(const CVectorReference4<InputType> &Vector):
										 CVectorReference4<Type>(m_Buffer[0],m_Buffer[1],m_Buffer[2],m_Buffer[3])
										 {
											m_x = (Type)Vector.m_x;
											m_y = (Type)Vector.m_y;
											m_z = (Type)Vector.m_z;
											m_w = (Type)Vector.m_w;
										 }
										 /// 拷貝建構式
										 template<typename InputType>
										 CVector4(const CVector2<InputType> &Vector, InputType z, InputType w):
										 CVectorReference4<Type>(m_Buffer[0],m_Buffer[1],m_Buffer[2],m_Buffer[3])
										 {
											m_x = (Type)Vector.m_x;
											m_y = (Type)Vector.m_y;
											m_z = (Type)z;
											m_w = (Type)w;
										 }
										 /// 拷貝建構式
										 template<typename InputType>
										 CVector4(const CVector3<InputType> &Vector, InputType w = 1):
										 CVectorReference4<Type>(m_Buffer[0],m_Buffer[1],m_Buffer[2],m_Buffer[3])
										 {
											m_x = (Type)Vector.m_x;
											m_y = (Type)Vector.m_y;
											m_z = (Type)Vector.m_z;
											m_w = (Type)w;
										 }
										 /// 拷貝建構式
										 template<typename InputType>
										 CVector4(const CVector4<InputType> &Vector):
										 CVectorReference4<Type>(m_Buffer[0],m_Buffer[1],m_Buffer[2],m_Buffer[3])
										 {
											m_x = (Type)Vector.m_x;
											m_y = (Type)Vector.m_y;
											m_z = (Type)Vector.m_z;
											m_w = (Type)Vector.m_w;
										 }

*/

			//////////////////////////////////////////////////////////////////////////
/*
										 /// 覆載對向量的 + 運算子
										 template<typename InputType>
			CVector4<Type>				 operator+(CVectorReference4<InputType> & Vector ){
											return Add(Vector);
										 }
										 /// 覆載對向量的 - 運算子
										 template<typename InputType>
			CVector4<Type>				 operator-(CVectorReference4<InputType> & Vector ){
											return Sub(Vector);
										 }
										 /// 覆載對實數的 * 運算子
			CVector4<Type>				 operator*(double Value ){
											return Mul(Value);
										 }
										 /// 覆載對向量的 * 運算子
										 template<typename InputType>
			CVector4<Type>				 operator*(CVectorReference4<InputType> & Vector ){
											return Mul(Vector);
										 }

										 /// 覆載對矩陣的 * 運算子
										 template<typename InputType>
			CVector4<Type>				 operator*(CMatrix4<InputType> & Matrix ){
											return Mul(Matrix);
										 }
										 /// 覆載對實數的 / 運算子
										 template<typename InputType>
			CVector4<Type>				 operator/(InputType Value ){
											return Div(Value);
										 }
										 /// 覆載對向量的 / 運算子
										 template<typename InputType>
			CVector4<Type>				 operator/(CVectorReference4<InputType> & Vector)
										 {
											 return Div(Vector);
										 }
*/
										 /// 覆載 = 運算子
			CVectorReference4<Type> &	 operator=(const CVectorReference4<float> & Vector){
											CVectorReference4<Type>::Assign(Vector);
											return *this;
										 }
										/// 覆載 = 運算子
			CVectorReference4<Type> &	operator=(const CVectorReference4<double> & Vector){
											CVectorReference4<Type>::Assign(Vector);
											return *this;
										}
/*
										 /// 覆載對向量的 += 運算子
										 template<typename InputType>
			CVectorReference4<Type>	&	 operator+=(CVectorReference4<InputType> & Vector ){
											AddAssign(Vector);
											return *this;
										 }
										 /// 覆載對向量的 -= 運算子
										 template<typename InputType>
			CVectorReference4<Type>	&	 operator-=(CVectorReference4<InputType> & Vector ){
											SubAssign(Vector);
											return *this;
										 }
										 /// 覆載對實數的 *= 運算子
			CVectorReference4<Type>	&	 operator*=(double  Value ){
											MulAssign(Value);
											return *this;
										 }
										 /// 覆載對向量的 *= 運算子
										 template<typename InputType>
			CVectorReference4<Type>	&	 operator*=(CVectorReference4<InputType> & Vector){
											MulAssign(Vector);
											return *this;
										 }

										 /// 覆載對矩陣的 *= 運算子
										 template<typename InputType>
			CVectorReference4<Type> &	 operator*=(CMatrix4<InputType> & Matrix ){
											MulAssign(Matrix);
											return *this;
										 }
										 /// 覆載對實數的 /= 運算子
										 template<typename InputType>
			CVectorReference4<Type>	&	 operator/=(InputType Value ){
											DivAssign(Value);
											return *this;
										 }
										 /// 覆載對向量的 /= 運算子
										 template<typename InputType>
			CVectorReference4<Type>	&	 operator/=(CVectorReference4<InputType> & Vector)
										 {
											 DivAssign(Vector);
											 return *this;
										 }

			//////////////////////////////////////////////////////////////////////////
										 /// 覆載對向量的 == 運算子
										 template<typename InputType>
			bool						 operator==(CVectorReference4<InputType> & Vector ){
											return Equal(Vector);
										 }
										 /// 覆載對向量的 != 運算子
										 template<typename InputType>
			bool						 operator!=(CVectorReference4<InputType> & Vector ){
											return !Equal(Vector);
										 }
										 /// 覆載對向量的 > 運算子
										 template<typename InputType>
			bool						 operator>(CVectorReference4<InputType> & Vector ){
											return Great(Vector);
										 }
										 /// 覆載對向量的 < 運算子
										 template<typename InputType>
			bool						 operator<(CVectorReference4<InputType> & Vector ){
											return Less(Vector);
										 }
										 /// 覆載對向量的 >= 運算子
										 template<typename InputType>
			bool						 operator>=(CVectorReference4<InputType> & Vector ){
											return GreatEqual(Vector);
										 }
										 /// 覆載對向量的 <= 運算子
										 template<typename InputType>
			bool						 operator<=(CVectorReference4<InputType> & Vector ){
											return LessEqual(Vector);
										 }
*/
};


/////////////////////////////////////////////////////////////////////////////////////////////
// Start Template
/// 2 x 2 的矩陣
template <typename Type>
class CMatrix2 {
										 /// 預設的單位矩陣
	static	const Type					 m_Identity[4];
public:
		
										 /// 對矩陣的緩衝區及各元素的定義
	union{
			struct {	Type			 m_Buffer[4];	};
			struct {	Type			 _M00,_M01,
										 _M10,_M11;		};
	};
										/// 矩陣使用的堆疊與索引(只有拷貝建構式會賦值)
	Type								m_StackBuffer[MATRIX_STACK_BUFFER_SIZE][4];
	int									m_StackIndex;

										/// 預定的建構式
										CMatrix2();	
										/// 以數值來指定初值的建構式
										template<typename InputType>
										CMatrix2(InputType  M00,InputType M01,InputType M10,InputType M11);	
										/// 以陣列來指定初值的建構式
										template<typename InputType>
										CMatrix2(InputType * Array);
										/// 拷貝建構式
										template<typename InputType>
										CMatrix2(const CMatrix2<InputType> & Matrix);

										///// 對 3x3 矩陣的拷貝建構式
										//template<typename InputType>
										//CMatrix2(CMatrix3<InputType> & Matrix){
										//	_M00 = (Type) Matrix._M00;
										//	_M10 = (Type) Matrix._M10;
										//	_M01 = (Type) Matrix._M01;
										//	_M11 = (Type) Matrix._M11;
										//}

										///// 對 4x4 矩陣的拷貝建構式
										//template<typename InputType>
										//CMatrix2(CMatrix4<InputType> & Matrix){
										//	_M00 = (Type) Matrix._M00;
										//	_M10 = (Type) Matrix._M10;
										//	_M01 = (Type) Matrix._M01;
										//	_M11 = (Type) Matrix._M11;
										// }

	virtual								~CMatrix2(){}
	
										/// 將資料放入堆疊
		virtual	CMatrix2<Type>		&	PushMatrix(void); 
										/// 由堆疊取出最後一個元素
		virtual	CMatrix2<Type>		&	PopMatrix(void); 
										/// 取得矩陣的緩衝區
			Type			*			GetBuffer(void);
										/// 取得反矩陣
			CMatrix2<Type>				GetInverse(void);
										/// 取得轉置矩陣
			CMatrix2<Type>				GetTranspose(void);
										/// 取得 DET 的結果
			double						GetDet(void);			
										/// 取得 Row Vector 必須使用拷貝建構式 
			CVectorReference2<Type>		GetRowVector(const int Index); 
										/// 取得 Column Vector 必須使用拷貝建構式
			CVectorReference2<Type>		GetColumnVector(const int Index); 			
			//////////////////////////////////////////////////////////////////////////
										/// 矩陣存入檔案
			bool						WriteMatrix(const char* FileName = nullptr);
										/// 由檔案讀入矩陣
			bool						ReadMatrix(const char * FileName = nullptr);
			/////////////////////////////////////////////////////////////////////////			
										/// 以陣列指定初值
										template<typename InputType>
			CMatrix2<Type>		&		SetMatrix(InputType * Array = nullptr);
										/// 設定縮放矩陣
			CMatrix2<Type>		&		SetScale(Type ScaleX = 1.0, Type ScaleY = 1.0);
										/// 追加旋轉矩陣
			CMatrix2<Type>		&		SetRotate(const double Deg); 
										/// 載入單位矩陣
			CMatrix2<Type>		&		LoadIdentity(void);
										/// 計算反矩陣
			CMatrix2<Type>		&		Inverse(void);
										/// 產生轉置矩陣
			CMatrix2<Type>		&		Transpose(void);
			//////////////////////////////////////////////////////////////////////////
										/// 覆載 + 法運算子
										template<typename InputType>
			CMatrix2<Type>				operator+(const CMatrix2<InputType> & Matrix);
										/// 覆載 - 法運算子
										template<typename InputType>
			CMatrix2<Type>				operator-(const CMatrix2<InputType> & Matrix);
										/// 覆載 * 法對實數的運算子
			CMatrix2<Type>				operator*(const double Value);
										/// 覆載 * 法對矩陣的運算子
										template<typename InputType>
			CMatrix2<Type>				operator*(const CMatrix2<InputType> & Matrix);
										/// 覆載 * 法對矩陣的運算子
										template<typename InputType>
			CVector2<Type>				operator*(const CVectorReference2<InputType> & Vector);
										/// 覆載 / 法對實數的運算子
			CMatrix2<Type>				operator/(const double Value);
										/// 使兩矩陣相等										
			CMatrix2<Type>		&		operator=(const CMatrix2<float> & Matrix);
										/// 使兩矩陣相等										
			CMatrix2<Type>		&		operator=(const CMatrix2<double> & Matrix);
										/// 覆載 += 法運算子
										template<typename InputType>
			CMatrix2<Type>		&		operator+=(const CMatrix2<InputType> & Matrix);
										/// 覆載 -= 法運算子
										template<typename InputType>
			CMatrix2<Type>		&		operator-=(const CMatrix2<InputType> & Matrix);
										/// 覆載 *= 法對實數的運算子
			CMatrix2<Type>		&		operator*=(const double Value);
										/// 覆載 *= 法對矩陣的運算子
										template<typename InputType>
			CMatrix2<Type>		&		operator*=(const CMatrix2<InputType> & Matrix);
										/// 覆載 /= 法對實數的運算子										
			CMatrix2<Type>		&		operator/=(const double Value);
protected:
										/// 使兩矩陣相加
										template<typename InputType>
			CMatrix2<Type>				Add(const CMatrix2<InputType> & Matrix);
										/// 使兩矩陣相減
										template<typename InputType>
			CMatrix2<Type>				Sub(const CMatrix2<InputType> & Matrix);
										///  矩陣與實數做乘法
			CMatrix2<Type>				Mul(const double Value);
										/// 矩陣的乘法
										template<typename InputType>
			CMatrix2<Type>				Mul(const CMatrix2<InputType> & Matrix);
										/// 矩陣的乘法
										template<typename InputType>
			CVector2<double>			Mul(const CVectorReference2<InputType>& Vector);
										///  矩陣與實數做除法
			CMatrix2<Type>				Div(const double Value);
										/// 使兩矩陣相等
										template<typename InputType>
			void						Assign(const CMatrix2<InputType> & Matrix);
										/// 計算兩矩陣相加並且保存數值
										template<typename InputType>
			void						AddAssign(const CMatrix2<InputType> &Matrix);
										/// 計算兩矩陣相減並且保存數值
										template<typename InputType>
			void						SubAssign(const CMatrix2<InputType> & Matrix);
										///  矩陣與實數做乘法並且保存數值
			void						MulAssign(const double Value);
										/// 計算兩矩陣相乘並且保存數值
										template<typename InputType>
			void						MulAssign(const CMatrix2<InputType> & Matrix);
										///  矩陣與實數做除法並且保存數值
			void						DivAssign(const double Value);
};

template <typename Type>
const Type CMatrix2<Type>::m_Identity[4] ={	1, 0,
											0, 1};

/// 3 x 3 的矩陣
template <typename Type>
class CMatrix3 {
public:
										 /// 預設的單位矩陣
	static	const Type					 m_Identity[9];

										 /// 對矩陣的緩衝區及各元素的定義
	union{
			struct {	Type			 m_Buffer[9];	};
			struct {	Type			 _M00, _M01, _M02,
										 _M10, _M11, _M12,
										 _M20, _M21, _M22;};
	};

										/// 矩陣使用的堆疊與索引(只有拷貝建構式會賦值)
	Type								m_StackBuffer[MATRIX_STACK_BUFFER_SIZE][9];
	int									m_StackIndex;

										/// 預定的建構式
										CMatrix3();
										/// 以數值來指定初值的建構式
										template<typename InputType>
										CMatrix3(	InputType M00, InputType M01, InputType  M02,
													InputType M10, InputType M11, InputType  M12,
													InputType M20, InputType M21, InputType  M22);
										/// 以陣列來指定初值的建構式
										template<typename InputType>
										CMatrix3(InputType* Array);
										/// 對 2 x 2 矩陣的建構式
										template<typename InputType>
										CMatrix3(CMatrix2<InputType>& Matrix);
										/// 對 3x3 矩陣的建構式
										template<typename InputType>
										CMatrix3(const CMatrix3<InputType>& Matrix); 

										///// 對 4x4 矩陣的拷貝建構式
										//template<typename InputType>
										//CMatrix3(CMatrix4<InputType> & Matrix){
										//	_M00 = (Type) Matrix._M00;	_M01 = (Type) Matrix._M01;	_M02 = (Type) Matrix._M02;
										//	_M10 = (Type) Matrix._M10;	_M11 = (Type) Matrix._M11;	_M12 = (Type) Matrix._M12;
										//	_M20 = (Type) Matrix._M20;	_M21 = (Type) Matrix._M21;	_M22 = (Type) Matrix._M22;
										// }

	virtual								~CMatrix3(){}
										/// 取得矩陣的緩衝區
			Type			*			GetBuffer(void);
										/// 取得反矩陣
			CMatrix3<Type>				GetInverse(void);
										/// 取得轉置矩陣
			CMatrix3<Type>				GetTranspose(void); 
										/// 取得 DET 的結果
			double						GetDet(void);
										/// 取得 Row Vector 必須使用拷貝建構式
			CVectorReference3<Type>		GetRowVector(const int Index);
										/// 取得 Column Vector 必須使用拷貝建構式
			CVectorReference3<Type>		GetColumnVector(const int Index);
			//////////////////////////////////////////////////////////////////////////
										/// 矩陣存入檔案
			bool						WriteMatrix(char* FileName = nullptr);
										/// 由檔案讀入矩陣
			bool						ReadMatrix(char* FileName = nullptr);
			/////////////////////////////////////////////////////////////////////////
										/// 以陣列指定初值
										template<typename InputType>
			CMatrix3<Type>		&		SetMatrix(InputType * Array);
										/// 將資料放入堆疊
	virtual	CMatrix3<Type>		&		PushMatrix(void);
										/// 由堆疊取出最後一個元素
	virtual	CMatrix3<Type>		&		PopMatrix(void);
										/// 追加平移矩陣
										template<typename InputType>
			CMatrix3<Type>		&		SetTranslate(InputType x, InputType y){
											CMatrix3<double> Matrix(	1,		0,		x,
																		0,		1,		y,
																		0,		0,		1);
											*this *= Matrix;
											return *this;
										}
										/// 追加平移矩陣
										template<typename InputType>
			CMatrix3<Type>		&		SetTranslate(CVectorReference2<InputType> & Position){
											CMatrix3<double> Matrix(	1,		0,		Position.m_x,
																		0,		1,		Position.m_y,
																		0,		0,		1);
											*this *= Matrix;
											return *this;
										}

										/// 追加旋轉矩陣
			CMatrix3<Type>		&		SetRotate(Type Angle){
											double Cos = (double) cos( 3.1415926 / 180 * Angle);
											double Sin = (double) sin( 3.1415926 / 180 * Angle);
											CMatrix3<double> Matrix(	Cos,	-Sin,		0,
																		Sin,	 Cos,		0,
																		0,		 0,			1);
											*this *= Matrix;
											return *this;
										}

										/// 追加旋轉矩陣
			CMatrix3<Type>		&		SetRotate(double Angle, Type x, Type y, Type z)
										{
											CVectorReference3<Type> Axis(x,y,z);
											Axis.Normalize();

											double Cos = (double) cos( Angle * 3.1415926f / 180);
											double Sin = (double) sin( Angle * 3.1415926f / 180);

											CMatrix3<double> Matrix( (double) (x * x * (1 - Cos) + Cos),		(double) (x * y * (1 - Cos) - z * Sin),	(double) (x * z * (1 - Cos) + y * Sin),
																	 (double) (y * x * (1 - Cos) + z * Sin),	(double) (y * y * (1 - Cos) + Cos),		(double) (y * z * (1 - Cos) - x * Sin),
																	 (double) (z * x * (1 - Cos) - y * Sin),	(double) (z * y * (1 - Cos) + x * Sin),	(double) (z * z * (1 - Cos) + Cos));
											*this *= Matrix;
											return *this;
										}
										/// 設定旋轉矩陣
										template<typename InputType>
			CMatrix3<Type>		&		SetRotate(double Angle, CVectorReference3<InputType> & Axis){
											Type x,y,z;
											CVectorReference3<Type> Vector(x,y,z);
											Vector = Axis;
											Vector.Normalize();

											double Cos = (double) cos( Angle * Deg2Rad);
											double Sin = (double) sin( Angle * Deg2Rad);

											CMatrix3<double> Matrix( (double) (x * x * (1 - Cos) + Cos),		(double) (x * y * (1 - Cos) - z * Sin),	(double) (x * z * (1 - Cos) + y * Sin),
																	 (double) (y * x * (1 - Cos) + z * Sin),	(double) (y * y * (1 - Cos) + Cos),		(double) (y * z * (1 - Cos) - x * Sin),
																	 (double) (z * x * (1 - Cos) - y * Sin),	(double) (z * y * (1 - Cos) + x * Sin),	(double) (z * z * (1 - Cos) + Cos));

											*this *= Matrix;
											return *this;
										}
										/// 設定縮放矩陣
			CMatrix3<Type>		&		SetScale(Type ScaleX = 1, Type ScaleY = 1, Type ScaleZ = 1)
										{
											CMatrix3<double> Matrix;
											Matrix._M00 = ScaleX;
											Matrix._M11 = ScaleY;
											Matrix._M22 = ScaleZ;
											*this *= Matrix;
											return *this;
										}
										/// 設定顏色轉換矩陣 RGB To YIQ
			CMatrix3<Type>		&		SetColorMatrixRGB2YIQ(void){
											_M00 =  (Type)0.299; _M01 = (Type) 0.587; _M02 = (Type) 0.114;
											_M10 =  (Type)0.596; _M11 = (Type)-0.274; _M12 = (Type)-0.322;
											_M20 =  (Type)0.211; _M21 = (Type)-0.523; _M22 = (Type) 0.312;
											return *this;
										}
										/// 設定顏色轉換矩陣 YIQ To RGB
			CMatrix3<Type>		&		SetColorMatrixYIQ2RGB(void){
											_M00 =  (Type)1.000; _M01 = (Type) 0.956; _M02 = (Type) 0.621;
											_M10 =  (Type)1.000; _M11 = (Type)-0.272; _M12 = (Type)-0.647;
											_M20 =  (Type)1.000; _M21 = (Type)-1.106; _M22 = (Type)-1.703;
											return *this;
										}
										/// 設定顏色轉換矩陣 RGB To YUV
			CMatrix3<Type>		&		SetColorMatrixRGB2YUV(void){
											_M00 = (Type) 0.299; _M01 = (Type) 0.587; _M02 = (Type) 0.114;
											_M10 = (Type)-0.148; _M11 = (Type)-0.289; _M12 = (Type) 0.437;
											_M20 = (Type) 0.615; _M21 = (Type)-0.515; _M22 = (Type)-0.100;
											return *this;
										}
										/// 設定顏色轉換矩陣 YUV To RGB
			CMatrix3<Type>		&		SetColorMatrixYUV2RGB(void){
											_M00 =  (Type)1.000; _M01 = (Type) 0.000; _M02 = (Type) 1.140;
											_M10 =  (Type)1.000; _M11 = (Type)-0.395; _M12 = (Type)-0.581;
											_M20 =  (Type)1.000; _M21 = (Type) 2.032; _M22 = (Type) 0.000;
											return *this;
										}
										/// 載入單位矩陣
			CMatrix3<Type>		&		LoadIdentity(void){
											memcpy(m_Buffer,m_Identity,sizeof(m_Identity));
											return *this;
										}
										/// 計算反矩陣
			CMatrix3<Type>		&		Inverse(void){
											double Det = GetDet();
											// 如果 Det = 0 代表沒有逆矩陣
											if(Det == 0){
												*this = CMatrix3<Type>(	0, 0, 0,
																		0, 0, 0,
																		0, 0, 0);
											}else{
												*this = CMatrix3<Type>(	 ( _M11 * _M22 - _M12 * _M21) / Det, -( _M01 * _M22 - _M21 * _M02) / Det,  ( _M01 * _M12 - _M11 * _M02) / Det,
																		-( _M10 * _M22 - _M12 * _M20) / Det,  ( _M00 * _M22 - _M20 * _M02) / Det, -( _M00 * _M12 - _M10 * _M02) / Det,
																		 ( _M10 * _M21 - _M20 * _M11) / Det, -( _M00 * _M21 - _M20 * _M01) / Det,  ( _M00 * _M11 - _M01 * _M10) / Det);
											}
											return *this;
										}
										/// 產生轉置矩陣
			CMatrix3<Type>		&		Transpose(void){
											*this = CMatrix3<Type>(	_M00, _M10, _M20,
																	_M01, _M11, _M21,
																	_M02, _M12, _M22);
											return *this;
										}
			//////////////////////////////////////////////////////////////////////////
										/// 覆載 + 法運算子
										template<typename InputType>
			CMatrix3<Type>				operator+(const CMatrix3<InputType> & Matrix){
											return Add(Matrix);
										}
										/// 覆載 - 法運算子
										template<typename InputType>
			CMatrix3<Type>				operator-(const CMatrix3<InputType> & Matrix){
											return Sub(Matrix);
										}
										/// 覆載 * 法對實數的運算子
			CMatrix3<Type>				operator*(const double Value){
											return Mul(Value);
										}
										/// 覆載 * 法對矩陣的運算子
										template<typename InputType>
			CMatrix3<Type>				operator*(const CMatrix3<InputType> & Matrix){
											return Mul(Matrix);
										}
										template<typename InputType>
			CVector3<Type>				operator*(const CVectorReference2<InputType> & Vector);
										/// 覆載 / 法對實數的運算子
			CMatrix3<Type>				operator/(const double Value){
											return Div(Value);
										}
										/// 使兩矩陣相等
			CMatrix3<Type>		&		operator=(const CMatrix3<float> & Matrix){
											Assign(Matrix);
											return *this;
										}
										/// 使兩矩陣相等
			CMatrix3<Type>		&		operator=(const CMatrix3<double> & Matrix){
											Assign(Matrix);
											return *this;
										}
										/// 覆載 += 法運算子
										template<typename InputType>
			CMatrix3<Type>		&		operator+=(const CMatrix3<InputType> & Matrix){
											AddAssign(Matrix);
											return *this;
										}
										/// 覆載 -= 法運算子
										template<typename InputType>
			CMatrix3<Type>		&		operator-=(const CMatrix3<InputType> & Matrix){
											SubAssign(Matrix);
											return *this;
										}
										/// 覆載 *= 法對實數的運算子
			CMatrix3<Type>		&		operator*=(const double Value){
											MulAssign(Value);
											return *this;
										}
										/// 覆載 *= 法對矩陣的運算子
										template<typename InputType>
			CMatrix3<Type>		&		operator*=(const CMatrix3<InputType> & Matrix){
											MulAssign(Matrix);
											return *this;
										}
										/// 覆載 /= 法對實數的運算子
			CMatrix3<Type>		&		operator/=(const double Value){
											DivAssign(Value);
											return *this;
										}
protected:
										/// 使兩矩陣相加
										template<typename InputType>
			CMatrix3<Type>				Add(const CMatrix3<InputType> & Matrix){
											return CMatrix3<Type>(	(Type)(_M00 + Matrix._M00),(Type)(_M01 + Matrix._M01),(Type)(_M02 + Matrix._M02),
																	(Type)(_M10 + Matrix._M10),(Type)(_M11 + Matrix._M11),(Type)(_M12 + Matrix._M12),
																	(Type)(_M20 + Matrix._M20),(Type)(_M21 + Matrix._M21),(Type)(_M22 + Matrix._M22));
										}
										/// 使兩矩陣相減
										template<typename InputType>
			CMatrix3<Type>				Sub(const CMatrix3<InputType> & Matrix){
											return CMatrix3<Type>(	(Type)(_M00 - Matrix._M00),(Type)(_M01 - Matrix._M01),(Type)(_M02 - Matrix._M02),
																	(Type)(_M10 - Matrix._M10),(Type)(_M11 - Matrix._M11),(Type)(_M12 - Matrix._M12),
																	(Type)(_M20 - Matrix._M20),(Type)(_M21 - Matrix._M21),(Type)(_M22 - Matrix._M22));
										}
										///  矩陣與實數做乘法
			CMatrix3<Type>				Mul(const double Value){
											return CMatrix3<Type>(	(Type)(_M00 * Value),(Type)(_M01 * Value),(Type)(_M02 * Value),
																	(Type)(_M10 * Value),(Type)(_M11 * Value),(Type)(_M12 * Value),
																	(Type)(_M20 * Value),(Type)(_M21 * Value),(Type)(_M22 * Value));
										}
										/// 矩陣的乘法
										template<typename InputType>
			CMatrix3<Type>				Mul(const CMatrix3<InputType> & Matrix){
											return CMatrix3<Type>(	_M00 * Matrix._M00 + _M01 * Matrix._M10 + _M02 * Matrix._M20,	_M00 * Matrix._M01 +_M01 * Matrix._M11 + _M02 * Matrix._M21,	_M00 * Matrix._M02 + _M01 * Matrix._M12 + _M02 * Matrix._M22,
																	_M10 * Matrix._M00 + _M11 * Matrix._M10 + _M12 * Matrix._M20,	_M10 * Matrix._M01 +_M11 * Matrix._M11 + _M12 * Matrix._M21,	_M10 * Matrix._M02 + _M11 * Matrix._M12 + _M12 * Matrix._M22,
																	_M20 * Matrix._M00 + _M21 * Matrix._M10 + _M22 * Matrix._M20,	_M20 * Matrix._M01 +_M21 * Matrix._M11 + _M22 * Matrix._M21,	_M20 * Matrix._M02 + _M21 * Matrix._M12 + _M22 * Matrix._M22);
										}
										/// 矩陣的乘法
										template<typename InputType>
			CVector3<double>			Mul(const CVectorReference2<InputType>& Vector){
											return CVector3<double>((double)_M00 * Vector.m_x + _M01 * Vector.m_y + _M02,
																	(double)_M10 * Vector.m_x + _M11 * Vector.m_y + _M12,
																	(double)_M20 * Vector.m_x + _M21 * Vector.m_y + _M22);
										}
										/// 矩陣的乘法
										template<typename InputType>
			CVector3<double>			Mul(const CVectorReference3<InputType>& Vector){
											return CVector3<double>((double)_M00 * Vector.m_x + _M01 * Vector.m_y + _M02 * Vector.m_z,
																	(double)_M10 * Vector.m_x + _M11 * Vector.m_y + _M12 * Vector.m_z,
																	(double)_M20 * Vector.m_x + _M21 * Vector.m_y + _M22 * Vector.m_z);
										}

										///  矩陣與實數做除法										
			CMatrix3<Type>				Div(const double Value){
											// 應該做例外判斷
											if(Value == 0)
												return *this;
											return CMatrix3<Type>(	(Type)(_M00 / Value),(Type)(_M01 / Value),(Type)(_M02 / Value),
																	(Type)(_M10 / Value),(Type)(_M11 / Value),(Type)(_M12 / Value),
																	(Type)(_M20 / Value),(Type)(_M21 / Value),(Type)(_M22 / Value));
										}
										/// 使兩矩陣相等
										template<typename InputType>
			void						Assign(const CMatrix3<InputType> & Matrix){
											_M00 = (Type) Matrix._M00; _M01 = (Type) Matrix._M01; _M02 = (Type) Matrix._M02;
											_M10 = (Type) Matrix._M10; _M11 = (Type) Matrix._M11; _M12 = (Type) Matrix._M12;
											_M20 = (Type) Matrix._M20; _M21 = (Type) Matrix._M21; _M22 = (Type) Matrix._M22;
										}
										/// 計算兩矩陣相加並且保存數值
										template<typename InputType>
			void						AddAssign(const CMatrix3<InputType> &Matrix){
											_M00 = (Type)(_M00 + Matrix._M00); _M01 = (Type)(_M01 + Matrix._M01); _M02 = (Type)(_M02 + Matrix._M02);
											_M10 = (Type)(_M10 + Matrix._M10); _M11 = (Type)(_M11 + Matrix._M11); _M12 = (Type)(_M12 + Matrix._M12);
											_M20 = (Type)(_M20 + Matrix._M20); _M21 = (Type)(_M21 + Matrix._M21); _M22 = (Type)(_M22 + Matrix._M22);

										}
										/// 計算兩矩陣相減並且保存數值
										template<typename InputType>
			void						SubAssign(const CMatrix3<InputType> Matrix){
											_M00 = (Type)(_M00 - Matrix._M00); _M01 = (Type)(_M01 - Matrix._M01); _M02 = (Type)(_M02 - Matrix._M02);
											_M10 = (Type)(_M10 - Matrix._M10); _M11 = (Type)(_M11 - Matrix._M11); _M12 = (Type)(_M12 - Matrix._M12);
											_M20 = (Type)(_M20 - Matrix._M20); _M21 = (Type)(_M21 - Matrix._M21); _M22 = (Type)(_M22 - Matrix._M22);
										}
										/// 計算兩矩陣相乘並且保存數值
										template<typename InputType>
			void						MulAssign(const CMatrix3<InputType> Matrix){
											*this = (*this).Mul(Matrix);
										}

										///  矩陣與實數做乘法並且保存數值
			void						MulAssign(const double Value){
											_M00 = (Type)(_M00 * Value); _M01 = (Type)(_M01 * Value); _M02 = (Type)(_M02 * Value);
											_M10 = (Type)(_M10 * Value); _M11 = (Type)(_M11 * Value); _M12 = (Type)(_M12 * Value);
											_M20 = (Type)(_M20 * Value); _M21 = (Type)(_M21 * Value); _M22 = (Type)(_M22 * Value);
										}

										///  矩陣與實數做除法並且保存數值										
			void						DivAssign(const double Value){
											// 應該做例外判斷
											if(Value == 0)
												return;
											_M00 = (Type)(_M00 / Value); _M01 = (Type)(_M01 / Value); _M02 = (Type)(_M02 / Value);
											_M10 = (Type)(_M10 / Value); _M11 = (Type)(_M11 / Value); _M12 = (Type)(_M12 / Value);
											_M20 = (Type)(_M20 / Value); _M21 = (Type)(_M21 / Value); _M22 = (Type)(_M22 / Value);
										}
};

template <typename Type>
const Type CMatrix3<Type>::m_Identity[9] = {	1, 0, 0,
												0, 1, 0,
												0, 0, 1};

//////////////////////////////////////////////////////////////////////////////////////////////////

/// 4 x 4 的矩陣
template <typename Type>
class CMatrix4 {
public:
										 /// 預設的單位矩陣
	static	const Type					 m_Identity[16];
										 /// 對矩陣的緩衝區及各元素的定義
	union{
			struct {	Type			 m_Buffer[16];	};
			struct {	Type			 _M00,_M10,_M20,_M30,
										 _M01,_M11,_M21,_M31,
										 _M02,_M12,_M22,_M32,
										 _M03,_M13,_M23,_M33;	};
	};
										/// 矩陣使用的堆疊與索引(只有拷貝建構式會賦值)
			Type						m_StackBuffer[MATRIX_STACK_BUFFER_SIZE][9];
			int							m_StackIndex;

										/// 預定的建構式
										CMatrix4() :
											m_StackIndex(0)
										{
											memcpy(m_Buffer,m_Identity,sizeof(m_Identity));
										}

										/// 以數值來指定初值的建構式
										template<typename InputType>
										CMatrix4(	const InputType M00, const InputType M01, const InputType M02, const InputType M03,
													const InputType M10, const InputType M11, const InputType M12, const InputType M13,
													const InputType M20, const InputType M21, const InputType M22, const InputType M23,
													const InputType M30, const InputType M31, const InputType M32, const InputType M33) :
											m_StackIndex(0) 
										{
											_M00 = (Type) M00; _M01 = (Type) M01; _M02 = (Type) M02; _M03 = (Type) M03;
											_M10 = (Type) M10; _M11 = (Type) M11; _M12 = (Type) M12; _M13 = (Type) M13;
											_M20 = (Type) M20; _M21 = (Type) M21; _M22 = (Type) M22; _M23 = (Type) M23;
											_M30 = (Type) M30; _M31 = (Type) M31; _M32 = (Type) M32; _M33 = (Type) M33;
										}

										/// 以陣列來指定初值的建構式
										template<typename InputType>
										CMatrix4(const InputType * Array) :
											m_StackIndex(0)
										{
											if(Array == nullptr){
												memcpy(m_Buffer,m_Identity,sizeof(m_Identity));
											}else{
												// _Mxx = (Type) *Array 然後 Array 平移到下一個
												_M00 = (Type) *Array++;	_M01 = (Type) *Array++; _M02 = (Type) *Array++;	_M03 = (Type) *Array++;	
												_M10 = (Type) *Array++; _M11 = (Type) *Array++;	_M12 = (Type) *Array++;	_M13 = (Type) *Array++;	
												_M20 = (Type) *Array++;	_M21 = (Type) *Array++; _M22 = (Type) *Array++;	_M23 = (Type) *Array++;	
												_M30 = (Type) *Array++;	_M31 = (Type) *Array++;	_M32 = (Type) *Array++;	_M33 = (Type) *Array++;
											}
										}
										/// 以 Alpha, Beta, Gamme 來初始化矩陣
										template<typename InputType>
										CMatrix4(	const InputType Alpha,	 const InputType Beta,	  const InputType Gamma,
													const InputType OffsetX, const InputType OffsetY, const InputType OffsetZ) :
											m_StackIndex(0)
										{

											double CosAlpha = cos(Alpha * Deg2Rad);
											double CosBeta	= cos(Beta  * Deg2Rad);
											double CosGamma = cos(Gamma * Deg2Rad);
											double SinAlpha = sin(Alpha * Deg2Rad);
											double SinBeta	= sin(Beta  * Deg2Rad);
											double SinGamma = sin(Gamma * Deg2Rad);

											_M00 = (Type) (CosAlpha * CosBeta);
											_M01 = (Type) (CosAlpha * SinBeta * SinGamma - SinAlpha * CosGamma);
											_M02 = (Type) (CosAlpha * SinBeta * CosGamma + SinAlpha * SinGamma);
											_M03 = (Type) (OffsetX);

											_M10 = (Type) (SinAlpha * CosBeta);
											_M11 = (Type) (SinAlpha * SinBeta * SinGamma + CosAlpha * CosGamma);
											_M12 = (Type) (SinAlpha * SinBeta * CosGamma - CosAlpha * SinGamma);
											_M13 = (Type) (OffsetY);

											_M20 = (Type) (-1 * SinBeta);
											_M21 = (Type) (CosBeta * SinGamma);
											_M22 = (Type) (CosBeta * CosGamma);
											_M23 = (Type) (OffsetZ);

											_M30 = (Type) 0;
											_M31 = (Type) 0;
											_M32 = (Type) 0;
											_M33 = (Type) 1;
										}
										/// 以 四元數 Q0,Qx,Qy,Qz Position初始化矩陣
										template<typename InputType>
										CMatrix4(const InputType Q0, const InputType Qx, const InputType Qy, const InputType Qz, const CVectorReference3<InputType> & Position) :
											m_StackIndex(0) 
										{
											_M00 = (Type)((Q0 * Q0) + (Qx * Qx) - (Qy * Qy) - (Qz * Qz));
											_M01 = (Type)(2 * ( ( Qx * Qy ) - ( Q0 * Qz ) ));
											_M02 = (Type)(2 * ( ( Qx * Qz ) + ( Q0 * Qy ) ));
											_M03 = (Type)Position.m_x;

											_M10 = (Type)(2 * (( Qx * Qy ) + ( Q0 * Qz )));
											_M11 = (Type)(( Q0 * Q0 ) - ( Qx * Qx ) + ( Qy * Qy ) - ( Qz * Qz ));
											_M12 = (Type)(2 * ( ( Qy * Qz ) - ( Q0 * Qx) ));
											_M13 = (Type)(Position.m_y);

											_M20 = (Type)(2 * ( ( Qx * Qz ) - ( Q0 * Qy ) ));
											_M21 = (Type)(2 * ( ( Qy * Qz ) + ( Q0 * Qx ) ));
											_M22 = (Type)(( Q0 * Q0 ) - ( Qx * Qx ) - ( Qy * Qy ) + ( Qz * Qz ));
											_M23 = (Type)(Position.m_z);

											_M30 = (Type)0;
											_M31 = (Type)0;
											_M32 = (Type)0;
											_M33 = (Type)1;
										}
										/// 對 2 x 2 矩陣的建構式
										template<typename InputType>
										CMatrix4(const CMatrix2<InputType> & Matrix) :
											m_StackIndex(0) 
										{
											_M00 = (Type) Matrix._M00; _M01 = (Type) Matrix._M01; _M02 = 0;	_M03 = 0;
											_M10 = (Type) Matrix._M10; _M11 = (Type) Matrix._M11; _M12 = 0; _M13 = 0;
											_M20 = 0;				   _M21 = 0;				  _M22 = 1;	_M23 = 0;
											_M30 = 0;				   _M31 = 0;				  _M32 = 0;	_M33 = 1;
										 }

										/// 對 3x3 矩陣的建構式
										template<typename InputType>
										CMatrix4(const CMatrix3<InputType> & Matrix) :
											m_StackIndex(0) 
										{
											_M00 = (Type) Matrix._M00; _M01 = (Type) Matrix._M01; _M02 = (Type) Matrix._M02; _M03 = (Type) 0;
											_M10 = (Type) Matrix._M10; _M11 = (Type) Matrix._M11; _M12 = (Type) Matrix._M12; _M13 = (Type) 0;
											_M20 = (Type) Matrix._M20; _M21 = (Type) Matrix._M21; _M22 = (Type) Matrix._M22; _M23 = (Type) 0;
											_M30 = (Type) 0;		   _M31 = (Type) 0;			  _M32 = (Type) 0;			 _M33 = (Type) 1;
										}

										/// 對 4x4 矩陣的拷貝建構式
										template<typename InputType>
										CMatrix4(const CMatrix4<InputType> & Matrix) :
											m_StackIndex(0) 
										{
											_M00 = (Type) Matrix._M00; _M01 = (Type) Matrix._M01; _M02 = (Type) Matrix._M02; _M03 = (Type) Matrix._M03;
											_M10 = (Type) Matrix._M10; _M11 = (Type) Matrix._M11; _M12 = (Type) Matrix._M12; _M13 = (Type) Matrix._M13;
											_M20 = (Type) Matrix._M20; _M21 = (Type) Matrix._M21; _M22 = (Type) Matrix._M22; _M23 = (Type) Matrix._M23;
											_M30 = (Type) Matrix._M30; _M31 = (Type) Matrix._M31; _M32 = (Type) Matrix._M32; _M33 = (Type) Matrix._M33;
										 }

	virtual								~CMatrix4(){}
										/// 取得矩陣的緩衝區
			Type			*			GetBuffer(void){
											return m_Buffer;
										}
										/// 取得反矩陣
			CMatrix4<Type>				GetInverse(void){
											double Det = GetDet();
											// 如果 Det = 0 代表沒有逆矩陣
											if(Det == 0){
												return CMatrix4<Type>(	0, 0, 0, 0,
																		0, 0, 0, 0,
																		0, 0, 0, 0,
																		0, 0, 0, 0);
											}

											// 計算各區域的伴隨矩陣
											double TDetM00,TDetM01,TDetM02,TDetM03;
											double TDetM10,TDetM11,TDetM12,TDetM13;
											double TDetM20,TDetM21,TDetM22,TDetM23;
											double TDetM30,TDetM31,TDetM32,TDetM33;


											TDetM00 = (double)(	_M11 * ( _M22 * _M33 - _M23 * _M32) -
																_M12 * ( _M21 * _M33 - _M23 * _M31) +
																_M13 * ( _M21 * _M32 - _M22 * _M31));

											TDetM01 = (double)(	_M01 * ( _M22 * _M33 - _M23 * _M32)	-
																_M02 * ( _M21 * _M33 - _M23 * _M31)	+
																_M03 * ( _M21 * _M32 - _M22 * _M31));

											TDetM02 = (double)( _M01 * ( _M12 * _M33 - _M13 * _M32) -
																_M02 * ( _M11 * _M33 - _M13 * _M31) +
																_M03 * ( _M11 * _M32 - _M12 * _M31));

											TDetM03 = (double)( _M01 * ( _M12 * _M23 - _M13 * _M22) -
																_M02 * ( _M11 * _M23 - _M13 * _M21)	+
																_M03 * ( _M11 * _M22 - _M12 * _M21));

											TDetM10 = (double)( _M10 * ( _M22 * _M33 - _M23 * _M32)	-
																_M12 * ( _M20 * _M33 - _M23 * _M30)	+
																_M13 * ( _M20 * _M32 - _M22 * _M30));

											TDetM11 = (double)( _M00 * ( _M22 * _M33 - _M23 * _M32)	-
																_M02 * ( _M20 * _M33 - _M23 * _M30)	+
																_M03 * ( _M20 * _M32 - _M22 * _M30));

											TDetM12 = (double)( _M00 * ( _M12 * _M33 - _M13 * _M32)	-
																_M02 * ( _M10 * _M33 - _M13 * _M30)	+
																_M03 * ( _M10 * _M32 - _M12 * _M30));

											TDetM13 = (double)( _M00 * ( _M12 * _M23 - _M13 * _M22)	-
																_M02 * ( _M10 * _M23 - _M13 * _M20)	+
																_M03 * ( _M10 * _M22 - _M12 * _M20));

											TDetM20 = (double)( _M10 * ( _M21 * _M33 - _M23 * _M31)	-
																_M11 * ( _M20 * _M33 - _M23 * _M30)	+
																_M13 * ( _M20 * _M31 - _M21 * _M30));

											TDetM21 = (double)( _M00 * ( _M21 * _M33 - _M23 * _M31)	-
																_M01 * ( _M20 * _M33 - _M23 * _M30)	+
																_M03 * ( _M20 * _M31 - _M21 * _M30));

											TDetM22 = (double)( _M00 * ( _M11 * _M33 - _M13 * _M31)	-
																_M01 * ( _M10 * _M33 - _M13 * _M30)	+
																_M03 * ( _M10 * _M31 - _M11 * _M30));

											TDetM23 = (double)( _M00 * ( _M11 * _M23 - _M13 * _M21)	-
																_M01 * ( _M10 * _M23 - _M13 * _M20)	+
																_M03 * ( _M10 * _M21 - _M11 * _M20));

											TDetM30 = (double)( _M10 * ( _M21 * _M32 - _M22 * _M31)	-
																_M11 * ( _M20 * _M32 - _M22 * _M30)	+
																_M12 * ( _M20 * _M31 - _M21 * _M30));

											TDetM31 = (double)( _M00 * ( _M21 * _M32 - _M22 * _M31)	-
																_M01 * ( _M20 * _M32 - _M22 * _M30)	+
																_M02 * ( _M20 * _M31 - _M21 * _M30));

											TDetM32 = (double)( _M00 * ( _M11 * _M32 - _M12 * _M31)	-
																_M01 * ( _M10 * _M32 - _M12 * _M30)	+
																_M02 * ( _M10 * _M31 - _M11 * _M30));

											TDetM33 = (double)( _M00 * ( _M11 * _M22 - _M12 * _M21)	-
																_M01 * ( _M10 * _M22 - _M12 * _M20) +
																_M02 * ( _M10 * _M21 - _M11 * _M20));

											return CMatrix4<Type>(	 TDetM00 / Det, -TDetM01 / Det,  TDetM02 / Det,	-TDetM03 / Det,
																	-TDetM10 / Det,  TDetM11 / Det, -TDetM12 / Det,	 TDetM13 / Det,
																	 TDetM20 / Det, -TDetM21 / Det,  TDetM22 / Det,	-TDetM23 / Det,
																	-TDetM30 / Det,	 TDetM31 / Det, -TDetM32 / Det,  TDetM33 / Det );
										}
										/// 取得轉置矩陣
			CMatrix4<Type>				GetTranspose(void){
											return CMatrix4<Type>(	_M00,_M10,_M20,_M30,
																	_M01,_M11,_M21,_M31,
																	_M02,_M12,_M22,_M32,
																	_M03,_M13,_M23,_M33);
										}
										/// 計算矩陣的 Det
			double						GetDet(void){
											double DetM00, DetM01, DetM02, DetM03;

											DetM00 = (double)(	_M11 * ( _M22 * _M33 - _M23 * _M32) -
																_M12 * ( _M21 * _M33 - _M23 * _M31) +
																_M13 * ( _M21 * _M32 - _M22 * _M31));

											DetM01 = (double)(  _M10 * ( _M22 * _M33 - _M23 * _M32) -
																_M12 * ( _M20 * _M33 - _M23 * _M30) +
																_M13 * ( _M20 * _M32 - _M22 * _M30));

											DetM02 = (double)(	_M10 * ( _M21 * _M33 - _M23 * _M31) -
																_M11 * ( _M20 * _M33 - _M23 * _M30) +
																_M13 * ( _M20 * _M31 - _M21 * _M30));

											DetM03 = (double)(	_M10 * ( _M21 * _M32 - _M22 * _M31) -
																_M11 * ( _M20 * _M32 - _M22 * _M30) +
																_M12 * ( _M20 * _M31 - _M21 * _M30));

											return (double)(_M00 * DetM00 - _M01 * DetM01 + _M02 * DetM02 - _M03 * DetM03);
										}
										/// 取得 Row Vector 必須使用拷貝建構式
			CVectorReference4<Type>		GetRowVector(const int Index){
											switch(Index){
											case 0:
												return CVectorReference4<Type>(_M00,_M01,_M02,_M03);
											case 1:
												return CVectorReference4<Type>(_M10,_M11,_M12,_M13);
											case 2:
												return CVectorReference4<Type>(_M20,_M21,_M22,_M23);
											case 3:
												return CVectorReference4<Type>(_M30,_M31,_M32,_M33);
											}
											return CVectorReference4<Type>(_M00,_M01,_M02,_M03);
										}
										/// 取得 Column Vector 必須使用拷貝建構式
			CVectorReference4<Type>		GetColumnVector(const int Index){
											switch(Index){
											case 0:
												return CVectorReference4<Type>(_M00,_M10,_M20,_M30);
											case 1:
												return CVectorReference4<Type>(_M01,_M11,_M21,_M31);
											case 2:
												return CVectorReference4<Type>(_M02,_M12,_M22,_M32);
											case 3:
												return CVectorReference4<Type>(_M03,_M13,_M23,_M33);
											}
											return CVectorReference4<Type>(_M00,_M10,_M20,_M30);
										}
										/// 取得 Axis ColumnVector 必須使用拷貝建構式
			CVectorReference3<Type>		GetAxisColumnVector(const int Index){
											switch(Index){
											case 0:
												return CVectorReference3<Type>(_M00,_M10,_M20);
											case 1:
												return CVectorReference3<Type>(_M01,_M11,_M21);
											case 2:
												return CVectorReference3<Type>(_M02,_M12,_M22);
											case 3:
												return CVectorReference3<Type>(_M03,_M13,_M23);
											}
											return CVectorReference3<Type>(_M00,_M10,_M20);
										}
										/// 取得 Axis Row Vector 必須使用拷貝建構式
			CVectorReference3<Type>		GetAxisRowVector(const int Index){
											switch(Index){
											case 0:
												return CVectorReference3<Type>(_M00,_M01,_M02);
											case 1:
												return CVectorReference3<Type>(_M10,_M11,_M12);
											case 2:
												return CVectorReference3<Type>(_M20,_M21,_M22);
											case 3:
												return CVectorReference3<Type>(_M30,_M31,_M32);
											}
											return CVectorReference3<Type>(_M00,_M10,_M20);
										}

										/// 取得矩陣的姿態????
										template<typename InputType>
			void						GetParameter(CVectorReference3<InputType> & Position,	double & Rx,	double & Ry,	double & Rz){
											Position.Set(_M03,_M13,_M23);
											double  GimballLock, TRx, TRy;
											Ry				= -asin(_M02);
											GimballLock		= cos(Ry);
											Ry				*= Rad2Deg;
											if( fabs(GimballLock) > 0.005){
												TRx =  _M22 / GimballLock;
												TRy = -_M12 / GimballLock;
												Rx  = atan2(TRy,TRx) * Rad2Deg;
												TRx =  _M00 / GimballLock;
												TRy = -_M01 / GimballLock;
												Rz	= atan2(TRy,TRx) * Rad2Deg;
											}else{
												Rx  =  0;
												TRx =  _M11;
												TRy =  _M10;
												Rz	= atan2(TRy,TRx) * (180.0f * 3.1415926f);
											}

										}
										/// 取得下三角矩陣
			CMatrix4<Type>				GetLowerTriangularMatrices(void)
										{
											CMatrix4<Type> UpperMatrix = GetUpperTriangularMatrices();
											CMatrix4<Type> LowerMatrix;
											CVectorReference4<Type> R0 = LowerMatrix.GetRowVector(0);
											CVectorReference4<Type> R1 = LowerMatrix.GetRowVector(1);
											CVectorReference4<Type> R2 = LowerMatrix.GetRowVector(2);
											CVectorReference4<Type> R3 = LowerMatrix.GetRowVector(3);

											LowerMatrix._M10 = _M10 / _M00;
											return CMatrix4<Type>();
										}
										/// 取得上三角矩陣
			CMatrix4<Type>				GetUpperTriangularMatrices(void)
										{
											CMatrix4<Type> Matrix(*this);
											CVectorReference4<Type> R0 = Matrix.GetRowVector(0);
											CVectorReference4<Type> R1 = Matrix.GetRowVector(1);
											CVectorReference4<Type> R2 = Matrix.GetRowVector(2);
											CVectorReference4<Type> R3 = Matrix.GetRowVector(3);

											R1 -= R0 /  (R0.m_x / R1.m_x);
											R2 -= R0 /  (R0.m_x / R2.m_x);
											R3 -= R0 /  (R0.m_x / R3.m_x);
											R2 -= R1 /  (R1.m_y / R2.m_y);
											R3 -= R1 /  (R1.m_y / R3.m_y);
											R3 -= R2 /  (R2.m_z / R3.m_z);
											return Matrix;
										}
			//////////////////////////////////////////////////////////////////////////
										/// 矩陣存入檔案
			bool						WriteMatrix(char * FileName = nullptr)
										{
											if(FileName == nullptr)
												FileName = "Matrix.txt";
											ofstream Fout;
											Fout.open(FileName, ios::out);

											if(Fout.is_open() == 0)
												return false;

											Fout << "row: "		<< 4 << '\n';
											Fout << "column: "	<< 4 << '\n';
											Fout << _M00   << ' ' << _M01 << ' ' << _M02 << ' ' <<  _M03 << '\n';
											Fout << _M10   << ' ' << _M11 << ' ' << _M12 << ' ' <<  _M13 << '\n';
											Fout << _M20   << ' ' << _M21 << ' ' << _M22 << ' ' <<  _M23 << '\n';
											Fout << _M30   << ' ' << _M31 << ' ' << _M32 << ' ' <<  _M33 << '\n';
											Fout.close();
											return true;
										}
										/// 由檔案讀入矩陣
			bool						ReadMatrix(char * FileName = nullptr)
										{
											if(FileName == nullptr)
												FileName = "Matrix.txt";
											ifstream Fin;
											Fin.open(FileName, ios::in);
											if(Fin.is_open() == 0)
												return false;

											char Buf[16];
											int row, column;
											double m00, m01, m02, m03;
											double m10, m11, m12, m13;
											double m20, m21, m22, m23;
											double m30, m31, m32, m33;
											// 判斷關鍵字
											Fin >> Buf;
											if(strcmp(Buf, "row:") != 0)
												return false;
											// 讀入列數
											Fin >> row;

											// 判斷關鍵字
											Fin >> Buf;
											if(strcmp(Buf, "column:") != 0)
												return false;
											// 讀入行數
											Fin >> column;

											// 判斷格式
											if(row != 4 || column != 4)
												return false;

											Fin >> m00 >> m01 >> m02 >>  m03 >> m10 >> m11 >> m12 >> m13 >> m20 >> m21 >> m22 >>  m23 >>  m30 >> m31 >> m32 >>  m33 ;
											_M00 = (Type)m00; _M01 = (Type)m01; _M02 = (Type)m02; _M03 = (Type)m03;
											_M10 = (Type)m10; _M11 = (Type)m11; _M12 = (Type)m12; _M13 = (Type)m13;
											_M20 = (Type)m20; _M21 = (Type)m21; _M22 = (Type)m22; _M23 = (Type)m23;
											_M30 = (Type)m30; _M31 = (Type)m31; _M32 = (Type)m32; _M33 = (Type)m33;

											Fin.close();
											return true;
										}
			/////////////////////////////////////////////////////////////////////////
										/// 以陣列指定初值
										template<typename InputType>
			CMatrix4<Type>		&		SetMatrix(InputType * Array){
											if(Array == nullptr){
												memcpy(m_Buffer,m_Identity,sizeof(m_Identity));
											}else{												
												// _Mxx = (Type) *Array 然後 Array 平移到下一個
												_M00 = (Type) *Array++; _M01 = (Type) *Array++; _M02 = (Type) *Array++; _M03 = (Type) *Array++;
												_M10 = (Type) *Array++;	_M11 = (Type) *Array++;	_M12 = (Type) *Array++;	_M13 = (Type) *Array++;
												_M20 = (Type) *Array++;	_M21 = (Type) *Array++;	_M22 = (Type) *Array++;	_M23 = (Type) *Array++;
												_M30 = (Type) *Array++;	_M31 = (Type) *Array++;	_M32 = (Type) *Array++;	_M33 = (Type) *Array++;
											}
											return *this;
										}

										/// 以 四元數 Q0,Qx,Qy,Qz Position初始化矩陣
										template<typename InputType>
			CMatrix4<Type>		&		SetMatrix(InputType Q0,InputType Qx, InputType Qy, InputType Qz, CVectorReference3<InputType> Position){
											_M00 = (Type) ( (Q0 * Q0) + (Qx * Qx) - (Qy * Qy) - (Qz * Qz) );
											_M01 = (Type) ( 2 * ( ( Qx * Qy ) - ( Q0 * Qz ) ) );
											_M02 = (Type) ( 2 * ( ( Qx * Qz ) + ( Q0 * Qy ) ) );
											_M03 = (Type) ( Position.m_x );

											_M10 = (Type) ( 2 * (( Qx * Qy ) + ( Q0 * Qz )) );
											_M11 = (Type) ( ( Q0 * Q0 ) - ( Qx * Qx ) + ( Qy * Qy ) - ( Qz * Qz ) );
											_M12 = (Type) ( 2 * ( ( Qy * Qz ) - ( Q0 * Qx) ) );
											_M13 = (Type) ( Position.m_y );

											_M20 = (Type) ( 2 * ( ( Qx * Qz ) - ( Q0 * Qy ) ) );
											_M21 = (Type) ( 2 * ( ( Qy * Qz ) + ( Q0 * Qx ) ) );
											_M22 = (Type) ( ( Q0 * Q0 ) - ( Qx * Qx ) - ( Qy * Qy ) + ( Qz * Qz ) );
											_M23 = (Type) ( Position.m_z );

											_M30 = (Type) ( 0 );
											_M31 = (Type) ( 0 );
											_M32 = (Type) ( 0 );
											_M33 = (Type) ( 1 );
											return *this;
										}
										/// 將資料放入堆疊
	virtual	void						PushMatrix(void){
											// 應加入例外
											if (m_StackIndex < MATRIX_STACK_BUFFER_SIZE)
												memcpy(m_StackBuffer[m_StackIndex++], m_Buffer, sizeof(m_Buffer));
											return *this;
										}
										/// 由堆疊取出最後一個元素
	virtual	void						PopMatrix(void){
											if (m_StackIndex > 0)
												memcpy(m_Buffer, m_StackBuffer[--m_StackIndex], sizeof(m_Buffer));
											return *this;
										}
										/// 設定平移
										template<typename InputType>
			CMatrix4<Type>		&		SetTranslate(InputType x, InputType y, InputType z) {
											CMatrix4<Type> Matrix(	(Type) 1,	(Type) 0,	(Type) 0,  (Type) x,
																	(Type) 0,	(Type) 1,	(Type) 0,  (Type) y,
																	(Type) 0,	(Type) 0,	(Type) 1,  (Type) z,
																	(Type) 0,	(Type) 0,	(Type) 0,  (Type) 1);
											*this *= Matrix;
											return *this;

										}
										/// 設定平移
										template<typename InputType>
			CMatrix4<Type>		&		SetTranslate(CVectorReference3<InputType> & Position) {
											CMatrix4<Type> Matrix(	(Type) 1,	(Type) 0,	(Type) 0,  (Type) Position.m_x,
																	(Type) 0,	(Type) 1,	(Type) 0,  (Type) Position.m_y,
																	(Type) 0,	(Type) 0,	(Type) 1,  (Type) Position.m_z,
																	(Type) 0,	(Type) 0,	(Type) 0,  (Type) 1);
											*this *= Matrix;
											return *this;

										}

										/// 設定旋轉矩陣
			CMatrix4<Type>		&		SetRotate(double Angle, Type x, Type y, Type z) {
											CVectorReference3<Type> Axis(x,y,z);
											Axis.Normalize();

											Type Cos = (Type) cos( Angle * 3.1415926f / 180);
											Type Sin = (Type) sin( Angle * 3.1415926f / 180);

											CMatrix4<Type>	 Matrix( (Type) (x * x * (1 - Cos) + Cos),		(Type) (x * y * (1 - Cos) - z * Sin),	(Type) (x * z * (1 - Cos) + y * Sin),	(Type) 0,
																	 (Type) (y * x * (1 - Cos) + z * Sin),	(Type) (y * y * (1 - Cos) + Cos),		(Type) (y * z * (1 - Cos) - x * Sin),	(Type) 0,
																	 (Type) (z * x * (1 - Cos) - y * Sin),	(Type) (z * y * (1 - Cos) + x * Sin),	(Type) (z * z * (1 - Cos) + Cos),		(Type) 0,
																	 (Type) 0,								(Type) 0,								(Type) 0,								(Type) 1);
											*this *= Matrix;
											return *this;
										}
										/// 設定旋轉矩陣
										template<typename InputType>
			CMatrix4<Type>		&		SetRotate(double Angle, CVectorReference3<InputType> & Axis){
											Type x,y,z;
											CVectorReference3<Type> Vector(x,y,z);
											Vector = Axis;
											Vector.Normalize();

											Type Cos = (Type) cos( Angle * 3.1415926f / 180);
											Type Sin = (Type) sin( Angle * 3.1415926f / 180);

											CMatrix4<Type>	 Matrix( (Type) (x * x * (1 - Cos) + Cos),		(Type) (x * y * (1 - Cos) - z * Sin),	(Type) (x * z * (1 - Cos) + y * Sin),	(Type) 0,
																	 (Type) (y * x * (1 - Cos) + z * Sin),	(Type) (y * y * (1 - Cos) + Cos),		(Type) (y * z * (1 - Cos) - x * Sin),	(Type) 0,
																	 (Type) (z * x * (1 - Cos) - y * Sin),	(Type) (z * y * (1 - Cos) + x * Sin),	(Type) (z * z * (1 - Cos) + Cos),		(Type) 0,
																	 (Type) 0,								(Type) 0,								(Type) 0,								(Type) 1);

											*this *= Matrix;
											return *this;
										}
										/// 設定縮放矩陣
										template<typename InputType>
			CMatrix4<Type>		&		SetScale(CVectorReference3<InputType> & Scale)
										{
											CMatrix4<Type> Matrix;
											Matrix._M00 = (Type) Scale.m_x;
											Matrix._M11 = (Type) Scale.m_y;
											Matrix._M22 = (Type) Scale.m_z;
											Matrix._M33 = (Type) 1;

											*this *= Matrix;
											return *this;
										}

										/// 設定縮放矩陣
			CMatrix4<Type>		&		SetScale(const Type ScaleX, const Type ScaleY, const Type ScaleZ)
										{
											CMatrix4<Type> Matrix;
											Matrix._M00 = ScaleX;
											Matrix._M11 = ScaleY;
											Matrix._M22 = ScaleZ;
											Matrix._M33 = (Type) 1;

											*this *= Matrix;
											return *this;
										}
										/// 設定為 Ortho 投射矩陣
			CMatrix4<Type>		&		Ortho(double Left,double Right,double Bottom,double Top,double Near,double Far){
											_M00 = (Type)(2 / (Right-Left));	_M01 = (Type)0;						_M02 = (Type)0;						_M03 = (Type)(-( Right + Left ) / ( Right - Left ));
											_M10 = (Type)0;						_M11 = (Type)(2 / (Top - Bottom));	_M12 = (Type)0;						_M13 = (Type)(-( Top + Bottom ) / ( Top - Bottom ));
											_M20 = (Type)0;						_M21 = (Type)0;						_M22 = (Type)(-2 / (Far - Near));	_M23 = (Type)(( Far + Near )   / ( Far - Near ));
											_M30 = (Type)0;						_M31 = (Type)0;						_M32 = (Type)0;						_M33 = (Type)1;
											return *this;
										}

										/// 設定為 Frustum 投射矩陣
			CMatrix4<Type>		&		Frustum(double Left,double Right,double Bottom,double Top,double Near,double Far){
											_M00 = (Type) ( 2 * Near/ (Right-Left) );	_M01 = (Type) ( 0 );							_M02 = (Type) ( ( Right + Left ) / ( Right - Left ) );		_M03 = (Type) ( 0 );
											_M10 = (Type) ( 0 );						_M11 = (Type) ( 2 * Near / (Top - Bottom) );	_M12 = (Type) ( ( Top + Bottom ) / ( Top - Bottom ) );		_M13 = (Type) ( 0 );
											_M20 = (Type) ( 0 );						_M21 = (Type) ( 0 );							_M22 = (Type) (-( Far + Near )   / ( Far - Near   ) );		_M23 = (Type) (-( 2 * Far * Near ) / ( Far - Near ));
											_M30 = (Type) ( 0 );						_M31 = (Type) ( 0 );							_M32 = (Type) ( -1 );										_M33 = (Type) ( 0 );
											return *this;
										}
										/// 設定為 Frustum 投射矩陣
			CMatrix4<Type>		&		Perspective(double Fovy, double Aspect, double zNear, double zFar){
											double f = 1 / tan(Fovy / 2 * 3.1415926 / 180);
											_M00 = (Type) ( f / Aspect );	_M01 = (Type) ( 0 );	_M02 = (Type) ( 0 );										_M03 = (Type) ( 0 );
											_M10 = (Type) ( 0 );			_M11 = (Type) ( f );	_M12 = (Type) ( 0 );										_M13 = (Type) ( 0 );
											_M20 = (Type) ( 0 );			_M21 = (Type) ( 0 );	_M22 = (Type) ( ( zNear + zFar) / ( zNear - zFar) );		_M23 = (Type) ( ( 2 * zFar * zNear ) / ( zNear - zFar ) );
											_M30 = (Type) ( 0 );			_M31 = (Type) ( 0 );	_M32 = (Type) (-1 );										_M33 = (Type) ( 0 );

											return *this;
										}
										/// 設定為 Lookat 攝影機矩陣
										template<typename InputType>
			CMatrix4<Type>		&		LookAt( CVectorReference3<InputType> & EyePos,
												CVectorReference3<InputType> & LookPoint,
												CVectorReference3<InputType> & Up){

											LoadIdentity();

											CVectorReference3<Type> RightVector	= GetAxisRowVector(0);
											CVectorReference3<Type> UpVector	= GetAxisRowVector(1);
											CVectorReference3<Type> LookVector	= GetAxisRowVector(2);

											LookVector	= EyePos - LookPoint;
											RightVector = Up ^ LookVector;
											UpVector	= LookVector ^ RightVector;
											LookVector.Normalize();
											UpVector.Normalize();
											RightVector.Normalize();
											SetTranslate(-EyePos.m_x,-EyePos.m_y,-EyePos.m_z);

											return *this;
										}

										/// 載入單位矩陣
			CMatrix4<Type>		&		LoadIdentity(void){
											memcpy(m_Buffer,m_Identity,sizeof(m_Identity));
											return *this;
										}
										/// 計算逆矩陣
			CMatrix4<Type>		&		Inverse(void){
											double Det = GetDet();
											// 如果 Det = 0 代表沒有逆矩陣
											if(Det == 0){
												*this = CMatrix4<Type>(	0,0,0,0,
																		0,0,0,0,
																		0,0,0,0,
																		0,0,0,0);
											}else{
												// 計算各區域的伴隨矩陣
												double TDetM00,TDetM01,TDetM02,TDetM03;
												double TDetM10,TDetM11,TDetM12,TDetM13;
												double TDetM20,TDetM21,TDetM22,TDetM23;
												double TDetM30,TDetM31,TDetM32,TDetM33;


												TDetM00 = (double)(	_M11 * ( _M22 * _M33 - _M23 * _M32) -
																	_M12 * ( _M21 * _M33 - _M23 * _M31) +
																	_M13 * ( _M21 * _M32 - _M22 * _M31));

												TDetM01 = (double)(	_M01 * ( _M22 * _M33 - _M23 * _M32)	-
																	_M02 * ( _M21 * _M33 - _M23 * _M31)	+
																	_M03 * ( _M21 * _M32 - _M22 * _M31));

												TDetM02 = (double)( _M01 * ( _M12 * _M33 - _M13 * _M32) -
																	_M02 * ( _M11 * _M33 - _M13 * _M31) +
																	_M03 * ( _M11 * _M32 - _M12 * _M31));

												TDetM03 = (double)( _M01 * ( _M12 * _M23 - _M13 * _M22) -
																	_M02 * ( _M11 * _M23 - _M13 * _M21)	+
																	_M03 * ( _M11 * _M22 - _M12 * _M21));

												TDetM10 = (double)( _M10 * ( _M22 * _M33 - _M23 * _M32)	-
																	_M12 * ( _M20 * _M33 - _M23 * _M30)	+
																	_M13 * ( _M20 * _M32 - _M22 * _M30));

												TDetM11 = (double)( _M00 * ( _M22 * _M33 - _M23 * _M32)	-
																	_M02 * ( _M20 * _M33 - _M23 * _M30)	+
																	_M03 * ( _M20 * _M32 - _M22 * _M30));

												TDetM12 = (double)( _M00 * ( _M12 * _M33 - _M13 * _M32)	-
																	_M02 * ( _M10 * _M33 - _M13 * _M30)	+
																	_M03 * ( _M10 * _M32 - _M12 * _M30));

												TDetM13 = (double)( _M00 * ( _M12 * _M23 - _M13 * _M22)	-
																	_M02 * ( _M10 * _M23 - _M13 * _M20)	+
																	_M03 * ( _M10 * _M22 - _M12 * _M20));

												TDetM20 = (double)( _M10 * ( _M21 * _M33 - _M23 * _M31)	-
																	_M11 * ( _M20 * _M33 - _M23 * _M30)	+
																	_M13 * ( _M20 * _M31 - _M21 * _M30));

												TDetM21 = (double)( _M00 * ( _M21 * _M33 - _M23 * _M31)	-
																	_M01 * ( _M20 * _M33 - _M23 * _M30)	+
																	_M03 * ( _M20 * _M31 - _M21 * _M30));

												TDetM22 = (double)( _M00 * ( _M11 * _M33 - _M13 * _M31)	-
																	_M01 * ( _M10 * _M33 - _M13 * _M30)	+
																	_M03 * ( _M10 * _M31 - _M11 * _M30));

												TDetM23 = (double)( _M00 * ( _M11 * _M23 - _M13 * _M21)	-
																	_M01 * ( _M10 * _M23 - _M13 * _M20)	+
																	_M03 * ( _M10 * _M21 - _M11 * _M20));

												TDetM30 = (double)( _M10 * ( _M21 * _M32 - _M22 * _M31)	-
																	_M11 * ( _M20 * _M32 - _M22 * _M30)	+
																	_M12 * ( _M20 * _M31 - _M21 * _M30));

												TDetM31 = (double)( _M00 * ( _M21 * _M32 - _M22 * _M31)	-
																	_M01 * ( _M20 * _M32 - _M22 * _M30)	+
																	_M02 * ( _M20 * _M31 - _M21 * _M30));

												TDetM32 = (double)( _M00 * ( _M11 * _M32 - _M12 * _M31)	-
																	_M01 * ( _M10 * _M32 - _M12 * _M30)	+
																	_M02 * ( _M10 * _M31 - _M11 * _M30));

												TDetM33 = (double)( _M00 * ( _M11 * _M22 - _M12 * _M21)	-
																	_M01 * ( _M10 * _M22 - _M12 * _M20) +
																	_M02 * ( _M10 * _M21 - _M11 * _M20));

												_M00 = (Type)  (TDetM00 / Det);
												_M01 = (Type) -(TDetM01 / Det);
												_M02 = (Type)  (TDetM02 / Det);
												_M03 = (Type) -(TDetM03 / Det);

												_M10 = (Type) -(TDetM10 / Det);
												_M11 = (Type)  (TDetM11 / Det);
												_M12 = (Type) -(TDetM12 / Det);
												_M13 = (Type)  (TDetM13 / Det);

												_M20 = (Type)  (TDetM20 / Det);
												_M21 = (Type) -(TDetM21 / Det);
												_M22 = (Type)  (TDetM22 / Det);
												_M23 = (Type) -(TDetM23 / Det);

												_M30 = (Type) -(TDetM30 / Det);
												_M31 = (Type)  (TDetM31 / Det);
												_M32 = (Type) -(TDetM32 / Det);
												_M33 = (Type)  (TDetM33 / Det);
											}
											return *this;
										}
										/// 產生轉置矩陣
			CMatrix4<Type>		&		Transpose(void){
											*this = CMatrix4<Type>(	_M00,_M10,_M20,_M30,
																	_M01,_M11,_M21,_M31,
																	_M02,_M12,_M22,_M32,
																	_M03,_M13,_M23,_M33);
											return * this;
										}
			//////////////////////////////////////////////////////////////////////////
										/// 覆載 + 法運算子
										template<typename InputType>
			CMatrix4<Type>				operator+(const CMatrix4<InputType> & Matrix){
											return Add(Matrix);
										}
										/// 覆載 - 法運算子
										template<typename InputType>
			CMatrix4<Type>				operator-(const CMatrix4<InputType> & Matrix){
											return Sub(Matrix);
										}
										/// 覆載 * 法對實數的運算子
			CMatrix4<Type>				operator*(const double Value){
											return Mul(Value);
										}
										///覆載 * 法對矩陣的運算子
										template<typename InputType>
			CMatrix4<Type>				operator*(const CMatrix4<InputType> & Matrix){
											return Mul(Matrix);
										}
										///覆載 * 法對矩陣的運算子
										template<typename InputType>
			CVector4<Type>				operator*(const CVectorReference3<InputType> & Vector){
											return Mul(Vector);
										}
										///覆載 * 法對矩陣的運算子
										template<typename InputType>
			CVector4<Type>				operator*(const CVectorReference4<InputType> & Vector){
											return Mul(Vector);
										}
										/// 覆載 / 法對實數的運算子
			CMatrix4<Type>				operator/(const double Value){
											return Div(Value);
										}
										/// 使兩矩陣相等
										template<typename InputType>
			CMatrix4<Type>		&		operator=(const CMatrix4<InputType> & Matrix){
											Assign(Matrix);
											return *this;
										}
										/// 覆載 += 法運算子
										template<typename InputType>
			CMatrix4<Type>		&		operator+=(const CMatrix4<InputType> & Matrix){
											AddAssign(Matrix);
											return *this;
										}
										/// 覆載 -= 法運算子
										template<typename InputType>
			CMatrix4<Type>		&		operator-=(const CMatrix4<InputType> & Matrix){
											SubAssign(Matrix);
											return *this;
										}
										/// 覆載 *= 法運算子
			CMatrix4<Type>		&		operator*=(const double Value){
											MulAssign(Value);
											return *this;
										}
										/// 覆載 *= 法對矩陣的運算子
										template<typename InputType>
			CMatrix4<Type>		&		operator*=(const CMatrix4<InputType> & Matrix){
											MulAssign(Matrix);
											return *this;
										}
										/// 覆載 /= 法對實數的運算子
			CMatrix4<Type>		&		operator/=(const double Value){
											DivAssign(Value);
											return *this;
										}
protected:
										/// 使兩矩陣相加
										template<typename InputType>
			CMatrix4<Type>				Add(const CMatrix4<InputType> & Matrix){
											return CMatrix4<Type>(	(Type)(_M00 + Matrix._M00),(Type)(_M01 + Matrix._M01),(Type)(_M02 + Matrix._M02),(Type)(_M03 + Matrix._M03),
																	(Type)(_M10 + Matrix._M10),(Type)(_M11 + Matrix._M11),(Type)(_M12 + Matrix._M12),(Type)(_M13 + Matrix._M13),
																	(Type)(_M20 + Matrix._M20),(Type)(_M21 + Matrix._M21),(Type)(_M22 + Matrix._M22),(Type)(_M23 + Matrix._M23),
																	(Type)(_M30 + Matrix._M30),(Type)(_M31 + Matrix._M31),(Type)(_M32 + Matrix._M32),(Type)(_M33 + Matrix._M33));
										}
										/// 使兩矩陣相減
										template<typename InputType>
			CMatrix4<Type>				Sub(const CMatrix4<InputType> & Matrix){
											return CMatrix4<Type>(	(Type)(_M00 - Matrix._M00),(Type)(_M01 - Matrix._M01),(Type)(_M02 - Matrix._M02),(Type)(_M03 - Matrix._M03),
																	(Type)(_M10 - Matrix._M10),(Type)(_M11 - Matrix._M11),(Type)(_M12 - Matrix._M12),(Type)(_M13 - Matrix._M13),
																	(Type)(_M20 - Matrix._M20),(Type)(_M21 - Matrix._M21),(Type)(_M22 - Matrix._M22),(Type)(_M23 - Matrix._M23),
																	(Type)(_M30 - Matrix._M30),(Type)(_M31 - Matrix._M31),(Type)(_M32 - Matrix._M32),(Type)(_M33 - Matrix._M33));

										}
										///  矩陣與實數做乘法
			CMatrix4<Type>				Mul(const double Value){
											return CMatrix4<Type>(	(Type)(_M00 * Value),(Type)(_M01 * Value),(Type)(_M02 * Value),(Type)(_M03 * Value),
																	(Type)(_M10 * Value),(Type)(_M11 * Value),(Type)(_M12 * Value),(Type)(_M13 * Value),
																	(Type)(_M20 * Value),(Type)(_M21 * Value),(Type)(_M22 * Value),(Type)(_M23 * Value),
																	(Type)(_M30 * Value),(Type)(_M31 * Value),(Type)(_M32 * Value),(Type)(_M33 * Value));
										}
										/// 矩陣的乘法
										template<typename InputType>
			CMatrix4<Type>				Mul(const CMatrix4<InputType> & Matrix){
											return CMatrix4<Type>(	_M00 * Matrix._M00 + _M01 * Matrix._M10 + _M02 * Matrix._M20 + _M03 * Matrix._M30,	_M00 * Matrix._M01 + _M01 * Matrix._M11 + _M02 * Matrix._M21 + _M03 * Matrix._M31,	_M00 * Matrix._M02 + _M01 * Matrix._M12 + _M02 * Matrix._M22 + _M03 * Matrix._M32,	_M00 * Matrix._M03 + _M01 * Matrix._M13 + _M02 * Matrix._M23 + _M03 * Matrix._M33,
																	_M10 * Matrix._M00 + _M11 * Matrix._M10 + _M12 * Matrix._M20 + _M13 * Matrix._M30,	_M10 * Matrix._M01 + _M11 * Matrix._M11 + _M12 * Matrix._M21 + _M13 * Matrix._M31,	_M10 * Matrix._M02 + _M11 * Matrix._M12 + _M12 * Matrix._M22 + _M13 * Matrix._M32,	_M10 * Matrix._M03 + _M11 * Matrix._M13 + _M12 * Matrix._M23 + _M13 * Matrix._M33,
																	_M20 * Matrix._M00 + _M21 * Matrix._M10 + _M22 * Matrix._M20 + _M23 * Matrix._M30,	_M20 * Matrix._M01 + _M21 * Matrix._M11 + _M22 * Matrix._M21 + _M23 * Matrix._M31,	_M20 * Matrix._M02 + _M21 * Matrix._M12 + _M22 * Matrix._M22 + _M23 * Matrix._M32,	_M20 * Matrix._M03 + _M21 * Matrix._M13 + _M22 * Matrix._M23 + _M23 * Matrix._M33,
																	_M30 * Matrix._M00 + _M31 * Matrix._M10 + _M32 * Matrix._M20 + _M33 * Matrix._M30,	_M30 * Matrix._M01 + _M31 * Matrix._M11 + _M32 * Matrix._M21 + _M33 * Matrix._M31,	_M30 * Matrix._M02 + _M31 * Matrix._M12 + _M32 * Matrix._M22 + _M33 * Matrix._M32,	_M30 * Matrix._M03 + _M31 * Matrix._M13 + _M32 * Matrix._M23 + _M33 * Matrix._M33);
										}
										/// 矩陣的乘法
										template<typename InputType>
			CVector4<double>			Mul(const CVectorReference3<InputType>& Vector){
											return CVector4<double>((double)_M00 * Vector.m_x + _M01 * Vector.m_y + _M02 * Vector.m_z + _M03,
																	(double)_M10 * Vector.m_x + _M11 * Vector.m_y + _M12 * Vector.m_z + _M13,
																	(double)_M20 * Vector.m_x + _M21 * Vector.m_y + _M22 * Vector.m_z + _M23,
																	(double)_M30 * Vector.m_x + _M31 * Vector.m_y + _M32 * Vector.m_z + _M33);
										}
										/// 矩陣的乘法
										template<typename InputType>
			CVector4<double>			Mul(const CVectorReference4<InputType>& Vector){
											return CVector4<double>((double)_M00 * Vector.m_x + _M01 * Vector.m_y + _M02 * Vector.m_z + _M03 * Vector.m_w,
																	(double)_M10 * Vector.m_x + _M11 * Vector.m_y + _M12 * Vector.m_z + _M13 * Vector.m_w,
																	(double)_M20 * Vector.m_x + _M21 * Vector.m_y + _M22 * Vector.m_z + _M23 * Vector.m_w,
																	(double)_M30 * Vector.m_x + _M31 * Vector.m_y + _M32 * Vector.m_z + _M33 * Vector.m_w);
										}
										///  矩陣與實數做除法										
			CMatrix4<Type>				Div(const double Value){
											// 應該做例外判斷
											if(Value == 0)
												return *this;
											return CMatrix4<Type>(	(Type)(_M00 / Value),(Type)(_M01 / Value),(Type)(_M02 / Value),(Type)(_M03 / Value),
																	(Type)(_M10 / Value),(Type)(_M11 / Value),(Type)(_M12 / Value),(Type)(_M13 / Value),
																	(Type)(_M20 / Value),(Type)(_M21 / Value),(Type)(_M22 / Value),(Type)(_M23 / Value),
																	(Type)(_M30 / Value),(Type)(_M31 / Value),(Type)(_M32 / Value),(Type)(_M33 / Value));
										}
										/// 使兩矩陣相等
										template<typename InputType>
			void						Assign(const CMatrix4<InputType> & Matrix){
											_M00 = (Type) Matrix._M00; _M01 = (Type) Matrix._M01; _M02 = (Type) Matrix._M02; _M03 = (Type) Matrix._M03;
											_M10 = (Type) Matrix._M10; _M11 = (Type) Matrix._M11; _M12 = (Type) Matrix._M12; _M13 = (Type) Matrix._M13;
											_M20 = (Type) Matrix._M20; _M21 = (Type) Matrix._M21; _M22 = (Type) Matrix._M22; _M23 = (Type) Matrix._M23;
											_M30 = (Type) Matrix._M30; _M31 = (Type) Matrix._M31; _M32 = (Type) Matrix._M32; _M33 = (Type) Matrix._M33;
										}
										/// 計算兩矩陣相加並且保存數值
										template<typename InputType>
			void						AddAssign(const CMatrix4<InputType> & Matrix){
											_M00 = (Type)(_M00 + Matrix._M00); _M01 = (Type)(_M01 + Matrix._M01); _M02 = (Type)(_M02 + Matrix._M02); _M03 = (Type)(_M03 + Matrix._M03);
											_M10 = (Type)(_M10 + Matrix._M10); _M11 = (Type)(_M11 + Matrix._M11); _M12 = (Type)(_M12 + Matrix._M12); _M13 = (Type)(_M13 + Matrix._M13);
											_M20 = (Type)(_M20 + Matrix._M20); _M21 = (Type)(_M21 + Matrix._M21); _M22 = (Type)(_M22 + Matrix._M22); _M23 = (Type)(_M23 + Matrix._M23);
											_M30 = (Type)(_M30 + Matrix._M30); _M31 = (Type)(_M31 + Matrix._M31); _M32 = (Type)(_M32 + Matrix._M32); _M33 = (Type)(_M33 + Matrix._M33);
										}
										/// 計算兩矩陣相減並且保存數值
										template<typename InputType>
			void						SubAssign(const CMatrix4<InputType> & Matrix){
											_M00 = (Type)(_M00 - Matrix._M00); _M01 = (Type)(_M01 - Matrix._M01); _M02 = (Type)(_M02 - Matrix._M02); _M03 = (Type)(_M03 - Matrix._M03);
											_M10 = (Type)(_M10 - Matrix._M10); _M11 = (Type)(_M11 - Matrix._M11); _M12 = (Type)(_M12 - Matrix._M12); _M13 = (Type)(_M13 - Matrix._M13);
											_M20 = (Type)(_M20 - Matrix._M20); _M21 = (Type)(_M21 - Matrix._M21); _M22 = (Type)(_M22 - Matrix._M22); _M23 = (Type)(_M23 - Matrix._M23);
											_M30 = (Type)(_M30 - Matrix._M30); _M31 = (Type)(_M31 - Matrix._M31); _M32 = (Type)(_M32 - Matrix._M32); _M33 = (Type)(_M33 - Matrix._M33);
										}
										/// 計算兩矩陣相乘並且保存數值
										template<typename InputType>
			void						MulAssign(const CMatrix4<InputType> & Matrix){
											*this = (*this).Mul(Matrix);
										}
										///  矩陣與實數做乘法並且保存數值
			void						MulAssign(const double Value){
											_M00 = (Type)(_M00 * Value); _M01 = (Type)(_M01 * Value); _M02 = (Type)(_M02 * Value); _M03 = (Type)(_M03 * Value);
											_M10 = (Type)(_M10 * Value); _M11 = (Type)(_M11 * Value); _M12 = (Type)(_M12 * Value); _M13 = (Type)(_M13 * Value);
											_M20 = (Type)(_M20 * Value); _M21 = (Type)(_M21 * Value); _M22 = (Type)(_M22 * Value); _M23 = (Type)(_M23 * Value);
											_M30 = (Type)(_M30 * Value); _M31 = (Type)(_M31 * Value); _M32 = (Type)(_M32 * Value); _M33 = (Type)(_M33 * Value);
										}
										///  矩陣與實數做除法並且保存數值
			void						DivAssign(const double Value){
											// 應該做例外判斷
											if(Value == 0)
												return;
											_M00 = (Type)(_M00 / Value); _M01 = (Type)(_M01 / Value); _M02 = (Type)(_M02 / Value); _M03 = (Type)(_M03 / Value);
											_M10 = (Type)(_M10 / Value); _M11 = (Type)(_M11 / Value); _M12 = (Type)(_M12 / Value); _M13 = (Type)(_M13 / Value);
											_M20 = (Type)(_M20 / Value); _M21 = (Type)(_M21 / Value); _M22 = (Type)(_M22 / Value); _M23 = (Type)(_M23 / Value);
											_M30 = (Type)(_M30 / Value); _M31 = (Type)(_M31 / Value); _M32 = (Type)(_M32 / Value); _M33 = (Type)(_M33 / Value);
										}
};
template <typename Type>
const Type CMatrix4<Type>::m_Identity[16] ={	1, 0, 0, 0,
												0, 1, 0, 0,
												0, 0, 1, 0,
												0, 0, 0, 1};



/////////////////////////////////////////////////////////////////////////////////////////////////
template<typename Type>
inline CVectorReference2<Type>::CVectorReference2(Type& Value0, Type& Value1) :
	m_x(Value0), m_y(Value1),
	m_s(Value0), m_t(Value1)
{
}
template<typename Type>
inline CVectorReference2<Type>::CVectorReference2(Type* Array) :
	m_x(Array[0]), m_y(Array[1]),
	m_s(Array[0]), m_t(Array[1])
{
}

template<typename Type>
inline CVectorReference2<Type>::~CVectorReference2() {}

template<typename Type>
inline CVectorReference2<Type>::CVectorReference2(const CVectorReference2<Type>& Vector) :
	m_x(Vector.m_x), m_y(Vector.m_y),
	m_s(Vector.m_s), m_t(Vector.m_t)
{
}

template<typename Type>
template<typename InputType>
inline CVectorReference2<Type>& CVectorReference2<Type>::Set(const InputType x, const InputType y) {
	m_x = (Type)x;
	m_y = (Type)y;
	return *this;
}

template<typename Type>
template<typename InputType>
inline CVectorReference2<Type>& CVectorReference2<Type>::Set(const InputType* Array) {
	m_x = (Type)Array[0];
	m_y = (Type)Array[1];
	return *this;
}

template<typename Type>
template<typename InputType>
inline double CVectorReference2<Type>::Dot(const CVectorReference2<InputType>& Vector) {
	return (double)m_x * Vector.m_x + m_y * Vector.m_y;
}

template<typename Type>
template<typename InputType>
inline void CVectorReference2<Type>::Swap(CVectorReference2<InputType>& Vector) {
	// 複製 Vector 的值
	CVector2<InputType> Temp;
	Temp = (Vector);
	Vector = *this;
	*this = Temp;
}

template<typename Type>
inline double CVectorReference2<Type>::GetLength(void) {
	double Size = (double)(m_x * m_x + m_y * m_y);
	return sqrt(Size);
}

template<typename Type>
template<typename InputType>
inline double CVectorReference2<Type>::GetAngle(const CVectorReference2<InputType>& Vector) {
	return GetRadian(Vector) * Rad2Deg;

}

template<typename Type>
template<typename InputType>
inline double CVectorReference2<Type>::GetRadian(const CVectorReference2<InputType>& Vector) {
	CVector2<double> v0, v1;
	v0 = (*this);
	v1 = Vector;
	double Length1 = v0.GetLength();
	double Length2 = v1.GetLength();
	double Length = Length1 * Length2;
	if (Length == 0)
		return 0;
	// 限制 在 -1 ~ 1 之間
	double Cos = max(-1.0, min(1.0, (*this).Dot(Vector) / Length));
	return acos(Cos);
}

template<typename Type>
inline CVector2<double> CVectorReference2<Type>::GetNormalize(void) {
	CVector2<double> v;
	v = (*this);
		double Length = v.GetLength();
	if (Length == 0)
		return v;
	return CVector2<double>((double)(m_x / Length), (double)(m_y / Length));
}

template<typename Type>
inline CVector2<double> CVectorReference2<Type>::GetReverse(void) {
	return CVector2<double>(-m_x, -m_y);
}

template<typename Type>
inline CVectorReference2<Type>& CVectorReference2<Type>::Normalize(void) {
	double Length = GetLength();
	if (Length == 0)
		return *this;
	m_x = (Type)(m_x / Length);
	m_y = (Type)(m_y / Length);
	return *this;
}

template<typename Type>
inline CVectorReference2<Type>& CVectorReference2<Type>::Reverse(void) {
	m_x = -m_x;
	m_y = -m_y;
	return *this;
}

template<typename Type>
inline bool CVectorReference2<Type>::IsZero(void) {
	double LengthPow2 = m_x * m_x + m_y * m_y;
	if (LengthPow2 > 0.000001)
		return false;
	return true;
}

template<typename Type>
template<typename InputType>
inline CVector2<Type> CVectorReference2<Type>::operator+(const CVectorReference2<InputType>& Vector) {
	return Add(Vector);
}

template<typename Type>
template<typename InputType>
inline CVector2<Type> CVectorReference2<Type>::operator-(const CVectorReference2<InputType>& Vector) {
	return Sub(Vector);
}

template<typename Type>
inline CVector2<Type> CVectorReference2<Type>::operator*(const double Value) {
	return Mul(Value);
}

template<typename Type>
template<typename InputType>
inline CVector2<Type> CVectorReference2<Type>::operator*(const CVectorReference2<InputType>& Vector) {
	return Mul(Vector);
}

template<typename Type>
inline CVector2<Type> CVectorReference2<Type>::operator/(const double Value) {
	return Div(Value);
}

template<typename Type>
template<typename InputType>
inline CVector2<Type> CVectorReference2<Type>::operator/(const CVectorReference2<InputType>& Vector) {
	return Div(Vector);
}

template<typename Type>
inline CVectorReference2<Type>& CVectorReference2<Type>::operator=(const CVectorReference2<float>& Vector) {
		Assign(Vector);
		return *this;
}
template<typename Type>
inline CVectorReference2<Type>& CVectorReference2<Type>::operator=(const CVectorReference2<double>& Vector) {
		Assign(Vector);
		return *this;
}

template<typename Type>
template<typename InputType>
inline CVectorReference2<Type>& CVectorReference2<Type>::operator+=(const CVectorReference2<InputType>& Vector) {
	AddAssign(Vector);
	return *this;
}

template<typename Type>
template<typename InputType>
inline CVectorReference2<Type>& CVectorReference2<Type>::operator-=(const CVectorReference2<InputType>& Vector) {
	SubAssign(Vector);
	return *this;
}

template<typename Type>
inline CVectorReference2<Type>& CVectorReference2<Type>::operator*=(const double Value) {
	MulAssign(Value);
	return *this;
}

template<typename Type>
template<typename InputType>
inline CVectorReference2<Type>& CVectorReference2<Type>::operator*=(const CVectorReference2<InputType>& Vector) {
	MulAssign(Vector);
	return *this;
}

template<typename Type>
inline CVectorReference2<Type>& CVectorReference2<Type>::operator/=(const double Value) {
	DivAssign(Value);
	return *this;
}

template<typename Type>
template<typename InputType>
inline CVectorReference2<Type>& CVectorReference2<Type>::operator/=(const CVectorReference2<InputType>& Vector) {
	DivAssign(Vector);
	return *this;
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference2<Type>::operator==(const CVectorReference2<InputType>& Vector) {
	return Equal(Vector);
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference2<Type>::operator!=(const CVectorReference2<InputType>& Vector) {
	return !Equal(Vector);
}
template<typename Type>
template<typename InputType>
inline bool CVectorReference2<Type>::operator>(const CVectorReference2<InputType>& Vector) {
	return Great(Vector);
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference2<Type>::operator<(const CVectorReference2<InputType>& Vector) {
	return Less(Vector);
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference2<Type>::operator>=(const CVectorReference2<InputType>& Vector) {
	return GreatEqual(Vector);
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference2<Type>::operator<=(const CVectorReference2<InputType>& Vector) {
	return LessEqual(Vector);
}

template<typename Type>
template<typename InputType>
inline CVector2<Type> CVectorReference2<Type>::Add(const CVectorReference2<InputType>& Vector) {
	return CVector2<Type>((Type)(m_x + Vector.m_x), (Type)(m_y + Vector.m_y));
}

template<typename Type>
template<typename InputType>
inline CVector2<Type> CVectorReference2<Type>::Sub(const CVectorReference2<InputType>& Vector) {
	return CVector2<Type>((Type)(m_x - Vector.m_x), (Type)(m_y - Vector.m_y));
}

template<typename Type>
inline CVector2<Type> CVectorReference2<Type>::Mul(const double Value) {
	return CVector2<Type>((Type)(m_x * Value), (Type)(m_y * Value));
}

template<typename Type>
template<typename InputType>
inline CVector2<Type> CVectorReference2<Type>::Mul(const CVectorReference2<InputType>& Vector) {
	return CVector2<Type>((Type)(m_x * Vector.m_x), (Type)(m_y * Vector.m_y));
}

template<typename Type>
inline CVector2<Type> CVectorReference2<Type>::Div(const double Value) {
	if (Value == 0) {

		return CVector2<Type>(*this);
	}
	return CVector2<Type>((Type)(m_x / Value), (Type)(m_y / Value));
}

template<typename Type>
template<typename InputType>
inline CVector2<Type> CVectorReference2<Type>::Div(const CVectorReference2<InputType>& Vector) {
	if (Vector.m_x == 0.0 || Vector.m_y == 0.0)
		return CVector2<Type>(*this);
	return CVector2<Type>((Type)((double)m_x / Vector.m_x), (Type)((double)m_y / Vector.m_y));
}

template<typename Type>
template<typename InputType>
inline void CVectorReference2<Type>::Assign(const CVectorReference2<InputType>& Vector) {
	m_x = (Type)Vector.m_x;
	m_y = (Type)Vector.m_y;
}

template<typename Type>
template<typename InputType>
inline void CVectorReference2<Type>::AddAssign(const CVectorReference2<InputType>& Vector) {
	m_x = (Type)((double)m_x + Vector.m_x);
	m_y = (Type)((double)m_y + Vector.m_y);
}

template<typename Type>
template<typename InputType>
inline void CVectorReference2<Type>::SubAssign(const CVectorReference2<InputType>& Vector) {
	m_x = (Type)(m_x - Vector.m_x);
	m_y = (Type)(m_y - Vector.m_y);
}

template<typename Type>
inline void CVectorReference2<Type>::MulAssign(const double Value) {
	m_x = (Type)(m_x * Value);
	m_y = (Type)(m_y * Value);
}

template<typename Type>
template<typename InputType>
inline void CVectorReference2<Type>::MulAssign(const CVectorReference2<InputType>& Vector) {
	m_x = (Type)(m_x * Vector.m_x);
	m_y = (Type)(m_y * Vector.m_y);
}

template<typename Type>
inline void CVectorReference2<Type>::DivAssign(const double Value) {
	if (Value == 0)
		return;
	m_x = (Type)(m_x / Value);
	m_y = (Type)(m_y / Value);
}

template<typename Type>
template<typename InputType>
inline void CVectorReference2<Type>::DivAssign(const CVectorReference2<InputType>& Vector) {
	if (Vector.m_x == 0.0 || Vector.m_y == 0.0)
		return;
	m_x = (Type)((double)m_x / Vector.m_x);
	m_y = (Type)((double)m_y / Vector.m_y);
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference2<Type>::Great(const CVectorReference2<InputType>& Vector) {
	if (m_x > Vector.m_x && m_y > Vector.m_y)
		return true;
	return false;
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference2<Type>::Less(const CVectorReference2<InputType>& Vector) {
	if (m_x < Vector.m_x && m_y < Vector.m_y)
		return true;
	return false;
}
template<typename Type>
template<typename InputType>
inline bool CVectorReference2<Type>::Equal(const CVectorReference2<InputType>& Vector) {
	CVector2<double> Temp((*this) - Vector);
	double LengthPow2 = Temp.m_x * Temp.m_x + Temp.m_y * Temp.m_y;
	if (LengthPow2 > 0.000001)
		return false;
	return true;
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference2<Type>::GreatEqual(const CVectorReference2<InputType>& Vector) {
	if (m_x >= Vector.m_x && m_y >= Vector.m_y)
		return true;
	return false;
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference2<Type>::LessEqual(const CVectorReference2<InputType>& Vector) {
	if (m_x <= Vector.m_x && m_y <= Vector.m_y)
		return true;
	return false;
}

///////////////////////////////////////////////////////////
/*
template<typename Type>
inline CVector2<Type>::CVector2() :
	CVectorReference2<Type>(m_Buffer[0], m_Buffer[1])
{
	m_Buffer[0] = 0;
	m_Buffer[1] = 0;
}
*/
template<typename Type>
template<typename InputType>
inline CVector2<Type>::CVector2(InputType Value0, InputType Value1) :
	CVectorReference2<Type>(m_Buffer[0], m_Buffer[1])
{
	m_Buffer[0] = (Type)Value0;
	m_Buffer[1] = (Type)Value1;
}

template<typename Type>
template<typename InputType>
inline CVector2<Type>::CVector2(InputType* Array) :
	CVectorReference2<Type>(m_Buffer[0], m_Buffer[1])
{
	if (Array == nullptr) {
		m_Buffer[0] = 0;
		m_Buffer[1] = 0;
	} else {
		m_Buffer[0] = (Type)Array[0];
		m_Buffer[1] = (Type)Array[1];
	}
}


/*
template<typename Type>
template<typename InputType>
inline CVector2<Type>::CVector2(const CVectorReference2<InputType>& Vector) :
	CVectorReference2<Type>(m_Buffer[0], m_Buffer[1])
{
	m_Buffer[0] = (Type)Vector.m_x;
	m_Buffer[1] = (Type)Vector.m_y;
}

template<typename Type>
template<typename InputType>
inline CVector2<Type>::CVector2(const CVector2<InputType>& Vector) :
	CVectorReference2<Type>(m_Buffer[0], m_Buffer[1])
{
	m_Buffer[0] = (Type)Vector.m_x;
	m_Buffer[1] = (Type)Vector.m_y;
}
*/

template<typename Type>
inline CVector2<Type>::~CVector2() {}
template<typename Type>
inline CVector2<Type>::CVector2(const CVectorReference2<Type>& Vector) :
	CVectorReference2<Type>(m_Buffer[0], m_Buffer[1])
{
	m_Buffer[0] = (Type)Vector.m_x;
	m_Buffer[1] = (Type)Vector.m_y;
}
template<typename Type>
inline CVector2<Type>::CVector2(const CVector2<Type>& Vector) :
	CVectorReference2<Type>(m_Buffer[0], m_Buffer[1])
{
	m_Buffer[0] = (Type)Vector.m_x;
	m_Buffer[1] = (Type)Vector.m_y;
}
/*
template<typename Type>
template<typename InputType>
inline CVector2<Type> CVector2<Type>::operator+(const CVectorReference2<InputType>& Vector) {
	return CVectorReference2<Type>::Add(Vector);
}

template<typename Type>
template<typename InputType>
inline CVector2<Type> CVector2<Type>::operator-(const CVectorReference2<InputType>& Vector) {
	return CVectorReference2<Type>::Sub(Vector);
}

template<typename Type>
template<typename InputType>
inline CVector2<Type> CVector2<Type>::operator*(const CVectorReference2<InputType>& Vector) {
	return CVectorReference2<Type>::Mul(Vector);
}

template<typename Type>
inline CVector2<Type> CVector2<Type>::operator*(const double Value) {
	return CVectorReference2<Type>::Mul(Value);
}

template<typename Type>
inline CVector2<Type> CVector2<Type>::operator/(const double Value) {
	return CVectorReference2<Type>::Div(Value);
}

template<typename Type>
template<typename InputType>
inline CVector2<Type> CVector2<Type>::operator/(const CVectorReference2<InputType>& Vector) {
	return CVectorReference2<Type>::Div(Vector);
}
*/
template<typename Type>
inline CVectorReference2<Type>& CVector2<Type>::operator=(const CVectorReference2<float>& Vector) {
	CVector2<Type>::Assign(Vector);
	return *this;
}

template<typename Type>
inline CVectorReference2<Type>& CVector2<Type>::operator=(const CVectorReference2<double>& Vector) {
	CVector2<Type>::Assign(Vector);
	return *this;
}
/*
template<typename Type>
template<typename InputType>
inline CVectorReference2<Type>& CVector2<Type>::operator+=(const CVectorReference2<InputType>& Vector) {
	CVectorReference2<Type>::AddAssign(Vector);
	return *this;
}

template<typename Type>
template<typename InputType>
inline CVectorReference2<Type>& CVector2<Type>::operator-=(const CVectorReference2<InputType>& Vector) {
	CVectorReference2<Type>::SubAssign(Vector);
	return *this;
}


template<typename Type>
inline CVectorReference2<Type>& CVector2<Type>::operator*=(const double Value) {
	CVectorReference2<Type>::MulAssign(Value);
	return *this;
}

template<typename Type>
template<typename InputType>
inline CVectorReference2<Type>& CVector2<Type>::operator*=(const CVectorReference2<InputType>& Vector) {
	CVectorReference2<Type>::MulAssign(Vector);
	return *this;
}

template<typename Type>
inline CVectorReference2<Type>& CVector2<Type>::operator/=(const double Value) {
	CVectorReference2<Type>::DivAssign(Value);
	return *this;
}

template<typename Type>
template<typename InputType>
inline CVectorReference2<Type>& CVector2<Type>::operator/=(const CVectorReference2<InputType>& Vector) {
	CVectorReference2<Type>::DivAssign(Vector);
	return *this;
}

template<typename Type>
template<typename InputType>
inline bool CVector2<Type>::operator==(const CVectorReference2<InputType>& Vector) {
	return CVectorReference2<Type>::Equal(Vector);
}

template<typename Type>
template<typename InputType>
inline bool CVector2<Type>::operator!=(const CVectorReference2<InputType>& Vector) {
	return !CVectorReference2<Type>::Equal(Vector);
}

template<typename Type>
template<typename InputType>
inline bool CVector2<Type>::operator>(const CVectorReference2<InputType>& Vector) {
	return CVectorReference2<Type>::Great(Vector);
}

template<typename Type>
template<typename InputType>
inline bool CVector2<Type>::operator<(const CVectorReference2<InputType>& Vector) {
	return CVectorReference2<Type>::Less(Vector);
}

template<typename Type>
template<typename InputType>
inline bool CVector2<Type>::operator>=(const CVectorReference2<InputType>& Vector) {
	return CVectorReference2<Type>::GreatEqual(Vector);
}

template<typename Type>
template<typename InputType>
inline bool CVector2<Type>::operator<=(const CVectorReference2<InputType>& Vector) {
	return CVectorReference2<Type>::LessEqual(Vector);
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////
template<typename Type>
inline CMatrix2<Type>::CMatrix2()
{
	memcpy(m_Buffer, m_Identity, sizeof(m_Identity));
	m_StackIndex = 0;
}

template<typename Type>
template<typename InputType>
inline CMatrix2<Type>::CMatrix2(InputType M00, InputType M01, InputType M10, InputType M11) {
	_M00 = (Type)M00;	_M01 = (Type)M01;
	_M10 = (Type)M10;	_M11 = (Type)M11;
	m_StackIndex = 0;
}

template<typename Type>
template<typename InputType>
inline CMatrix2<Type>::CMatrix2(InputType* Array) {
	if (Array == nullptr) {
		memcpy(m_Buffer, m_Identity, sizeof(m_Identity));
	} else {
		// _Mxx = (Type) *Array 然後 Array 平移到下一個
		_M00 = (Type)*Array++;	_M01 = (Type)*Array++;
		_M10 = (Type)*Array++;	_M11 = (Type)*Array++;
	}
	m_StackIndex = 0;
}

template<typename Type>
template<typename InputType>
inline CMatrix2<Type>::CMatrix2(const CMatrix2<InputType>& Matrix) {
	_M00 = (Type)Matrix._M00;	_M10 = (Type)Matrix._M10;
	_M01 = (Type)Matrix._M01;	_M11 = (Type)Matrix._M11;

	m_StackIndex = Matrix.m_StackIndex;
	memcpy(m_StackBuffer, Matrix.m_StackBuffer, sizeof(m_StackBuffer));
}

template<typename Type>
inline CMatrix2<Type>& CMatrix2<Type>::PushMatrix(void) {
	// 應加入例外
	if (m_StackIndex < MATRIX_STACK_BUFFER_SIZE)
		memcpy(m_StackBuffer[m_StackIndex++], m_Buffer, sizeof(m_Buffer));
	return *this;
}

template<typename Type>
inline CMatrix2<Type>& CMatrix2<Type>::PopMatrix(void) {
	if (m_StackIndex > 0)
		memcpy(m_Buffer, m_StackBuffer[--m_StackIndex], sizeof(m_Buffer));
	return *this;
}

template<typename Type>
inline Type* CMatrix2<Type>::GetBuffer(void) {
	return m_Buffer;
}

template<typename Type>
inline CMatrix2<Type> CMatrix2<Type>::GetInverse(void) {
	double Det = GetDet();
	// 如果 Det = 0 代表沒有逆矩陣
	if (Det == 0) {
		return CMatrix2<Type>(0, 0, 0, 0);
	}
	return CMatrix2<Type>(	 _M11 / Det, -_M01 / Det,
							-_M10 / Det,  _M00 / Det);
}

template<typename Type>
inline CMatrix2<Type> CMatrix2<Type>::GetTranspose(void) {
	return CMatrix2<Type>(	_M00, _M10,
							_M01, _M11);
}

template<typename Type>
inline double CMatrix2<Type>::GetDet(void) {
	return ((double)_M00 * _M11 - _M01 * _M10);
}

template<typename Type>
inline CVectorReference2<Type> CMatrix2<Type>::GetRowVector(const int Index) {
	switch (Index) {
	case 0:
		return CVectorReference2<Type>(_M00, _M01);
	case 1:
		return CVectorReference2<Type>(_M10, _M11);
	}
	return CVectorReference2<Type>(_M00, _M01);
}

template<typename Type>
inline CVectorReference2<Type> CMatrix2<Type>::GetColumnVector(const int Index) {
	switch (Index) {
	case 0:
		return CVectorReference2<Type>(_M00, _M10);
	case 1:
		return CVectorReference2<Type>(_M01, _M11);
	}
	return CVectorReference2<Type>(_M00, _M10);
}

template<typename Type>
inline bool CMatrix2<Type>::WriteMatrix(const char* FileName) {
	if (FileName == nullptr)
		FileName = "Matrix.txt";
	std::ofstream Fout;
	Fout.open(FileName, ios::out);

	if (Fout.is_open() == 0)
		return false;

	Fout << "row: " << 2 << '\n';
	Fout << "column: " << 2 << '\n';
	Fout << _M00 << ' ' << _M01 << '\n';
	Fout << _M10 << ' ' << _M11 << '\n';
	Fout.close();
	return true;
}

template<typename Type>
inline bool CMatrix2<Type>::ReadMatrix(const char* FileName) {
	if (FileName == NULL)
		FileName = "Matrix.txt";
	ifstream Fin;
	Fin.open(FileName, ios::in);
	if (Fin.is_open() == 0)
		return false;

	char Buf[16];
	int row, column;
	double m00, m01, m10, m11;
	// 判斷關鍵字
	Fin >> Buf;
	if (strcmp(Buf, "row:") != 0)
		return false;
	// 讀入列數
	Fin >> row;

	// 判斷關鍵字
	Fin >> Buf;
	if (strcmp(Buf, "column:") != 0)
		return false;
	// 讀入行數
	Fin >> column;

	// 判斷格式
	if (row != 2 || column != 2)
		return false;

	Fin >> m00 >> m01 >> m10 >> m11;
	_M00 = (Type)m00;
	_M01 = (Type)m01;
	_M10 = (Type)m10;
	_M11 = (Type)m11;

	Fin.close();
	return true;
}

template<typename Type>
template<typename InputType>
inline CMatrix2<Type>& CMatrix2<Type>::SetMatrix(InputType* Array) {
	if (Array == NULL) {
		memcpy(m_Buffer, m_Identity, sizeof(m_Identity));
	}
	else {
		Type* Buffer = m_Buffer;
		// _Mxx = (Type) *Array 然後 Array 平移到下一個
		_M00 = (Type)*Array++; _M01 = (Type)*Array++;
		_M10 = (Type)*Array++; _M11 = (Type)*Array++;
	}
	return *this;
}

template<typename Type>
inline CMatrix2<Type>& CMatrix2<Type>::SetScale(Type ScaleX, Type ScaleY) {
	CMatrix2<Type> Matrix(ScaleX, 0.0, 0.0, ScaleY);
	*this *= Matrix;
	return *this;
}

template<typename Type>
inline CMatrix2<Type>& CMatrix2<Type>::SetRotate(const double Deg) {
	double Cos = cos(Deg * Deg2Rad);
	double Sin = sin(Deg * Deg2Rad);
	CMatrix2<Type> Matrix(Cos, -Sin,
		Sin, Cos);
	*this *= Matrix;
	return *this;
}

template<typename Type>
inline CMatrix2<Type>& CMatrix2<Type>::LoadIdentity(void) {
	memcpy(m_Buffer, m_Identity, sizeof(m_Identity));
	return *this;
}

template<typename Type>
inline CMatrix2<Type>& CMatrix2<Type>::Inverse(void) {
	double Det = GetDet();
	if (Det == 0) {
		*this = CMatrix2<Type>(0, 0, 0, 0);
	} else {
		*this = CMatrix2<Type>(	 _M11 / Det, -_M01 / Det, 
								-_M10 / Det,  _M00 / Det);
	}
	return *this;
}

template<typename Type>
inline CMatrix2<Type>& CMatrix2<Type>::Transpose(void) {
	*this = CMatrix2<Type>(_M00, _M10, _M01, _M11);
	return *this;
}

template<typename Type>
template<typename InputType>
inline CMatrix2<Type> CMatrix2<Type>::operator+(const CMatrix2<InputType>& Matrix) {
	return Add(Matrix);
}

template<typename Type>
template<typename InputType>
inline CMatrix2<Type> CMatrix2<Type>::operator-(const CMatrix2<InputType>& Matrix) {
	return Sub(Matrix);
}

template<typename Type>
inline CMatrix2<Type> CMatrix2<Type>::operator*(const double Value) {
	return Mul(Value);
}

template<typename Type>
template<typename InputType>
inline CMatrix2<Type> CMatrix2<Type>::operator*(const CMatrix2<InputType>& Matrix) {
	return Mul(Matrix);
}

template<typename Type>
template<typename InputType>
inline CVector2<Type> CMatrix2<Type>::operator*(const CVectorReference2<InputType>& Vector) {
	return Mul(Vector);
}

template<typename Type>
inline CMatrix2<Type> CMatrix2<Type>::operator/(const double Value) {
	return Div(Value);
}

template<typename Type>
inline CMatrix2<Type>& CMatrix2<Type>::operator=(const CMatrix2<float>& Matrix) {
	Assign(Matrix);
	return *this;
}

template<typename Type>
inline CMatrix2<Type>& CMatrix2<Type>::operator=(const CMatrix2<double>& Matrix) {
	Assign(Matrix);
	return *this;
}


template<typename Type>
template<typename InputType>
inline CMatrix2<Type>& CMatrix2<Type>::operator+=(const CMatrix2<InputType>& Matrix) {
	AddAssign(Matrix);
	return *this;
}

template<typename Type>
template<typename InputType>
inline CMatrix2<Type>& CMatrix2<Type>::operator-=(const CMatrix2<InputType>& Matrix) {
	SubAssign(Matrix);
	return *this;
}


template<typename Type>
inline CMatrix2<Type>& CMatrix2<Type>::operator*=(const double Value) {
	MulAssign(Value);
	return *this;
}

template<typename Type>
template<typename InputType>
inline CMatrix2<Type>& CMatrix2<Type>::operator*=(const CMatrix2<InputType>& Matrix) {
	MulAssign(Matrix);
	return *this;
}

template<typename Type>
inline CMatrix2<Type>& CMatrix2<Type>::operator/=(const double Value) {
	DivAssign(Value);
	return *this;
}

template<typename Type>
template<typename InputType>
inline CMatrix2<Type> CMatrix2<Type>::Add(const CMatrix2<InputType>& Matrix) {
	return CMatrix2<Type>((Type)(_M00 + Matrix._M00), (Type)(_M01 + Matrix._M01),
		(Type)(_M10 + Matrix._M10), (Type)(_M11 + Matrix._M11));
}

template<typename Type>
template<typename InputType>
inline CMatrix2<Type> CMatrix2<Type>::Sub(const CMatrix2<InputType>& Matrix) {
	return CMatrix2<Type>(	(Type)(_M00 - Matrix._M00), (Type)(_M01 - Matrix._M01),
							(Type)(_M10 - Matrix._M10), (Type)(_M11 - Matrix._M11));
}

template<typename Type>
inline CMatrix2<Type> CMatrix2<Type>::Mul(const double Value) {
	return CMatrix2<Type>(	(Type)(_M00 * Value), (Type)(_M01 * Value),
							(Type)(_M10 * Value), (Type)(_M11 * Value));
}

template<typename Type>
template<typename InputType>
inline CMatrix2<Type> CMatrix2<Type>::Mul(const CMatrix2<InputType>& Matrix) {
	return CMatrix2<Type>(	_M00 * Matrix._M00 + _M01 * Matrix._M10, _M00 * Matrix._M01 + _M01 * Matrix._M11,
							_M10 * Matrix._M00 + _M11 * Matrix._M10, _M10 * Matrix._M01 + _M11 * Matrix._M11);
}

template<typename Type>
template<typename InputType>
inline CVector2<double> CMatrix2<Type>::Mul(const CVectorReference2<InputType>& Vector) {
	return CVector2<double>(	(double)_M00 * Vector.m_x + _M01 * Vector.m_y,
								(double)_M10 * Vector.m_x + _M11 * Vector.m_y);
}

template<typename Type>
inline CMatrix2<Type> CMatrix2<Type>::Div(const double Value) {
	// 應該做例外判斷
	if (Value == 0)
		return *this;
	return CMatrix2<Type>(	(Type)(_M00 / Value), (Type)(_M01 / Value),
							(Type)(_M10 / Value), (Type)(_M11 / Value));
}

template<typename Type>
template<typename InputType>
inline void CMatrix2<Type>::Assign(const CMatrix2<InputType>& Matrix) {
	_M00 = (Type)Matrix._M00;	_M01 = (Type)Matrix._M01;
	_M10 = (Type)Matrix._M10;	_M11 = (Type)Matrix._M11;
}

template<typename Type>
template<typename InputType>
inline void CMatrix2<Type>::AddAssign(const CMatrix2<InputType>& Matrix) {
	_M00 = (Type)(_M00 + Matrix._M00);	_M01 = (Type)(_M01 + Matrix._M01);
	_M10 = (Type)(_M10 + Matrix._M10);	_M11 = (Type)(_M11 + Matrix._M11);
}

template<typename Type>
template<typename InputType>
inline void CMatrix2<Type>::SubAssign(const CMatrix2<InputType>& Matrix) {
	_M00 = (Type)(_M00 - Matrix._M00);	_M01 = (Type)(_M01 - Matrix._M01);
	_M10 = (Type)(_M10 - Matrix._M10);	_M11 = (Type)(_M11 - Matrix._M11);
}

template<typename Type>
inline void CMatrix2<Type>::MulAssign(const double Value) {
	_M00 = (Type)(_M00 * Value);	_M01 = (Type)(_M01 * Value);
	_M10 = (Type)(_M10 * Value);	_M11 = (Type)(_M11 * Value);
}

template<typename Type>
template<typename InputType>
inline void CMatrix2<Type>::MulAssign(const CMatrix2<InputType>& Matrix) {
	*this = (*this).Mul(Matrix);
}

template<typename Type>
inline void CMatrix2<Type>::DivAssign(const double Value) {
	// 應該做例外判斷
	if (Value == 0)
		return;
	_M00 = (Type)(_M00 / Value);	_M01 = (Type)(_M01 / Value);
	_M10 = (Type)(_M10 / Value);	_M11 = (Type)(_M11 / Value);
}

template<typename Type>
inline CVectorReference3<Type>::CVectorReference3(Type& Value0, Type& Value1, Type& Value2) :
	m_x(Value0), m_y(Value1), m_z(Value2),
	m_s(Value0), m_t(Value1), m_p(Value2),
	m_r(Value0), m_g(Value1), m_b(Value2)
{
}

template<typename Type>
inline CVectorReference3<Type>::CVectorReference3(Type* Array) :
	m_x(Array[0]), m_y(Array[1]), m_z(Array[2]),
	m_s(Array[0]), m_t(Array[1]), m_p(Array[2]),
	m_r(Array[0]), m_g(Array[1]), m_b(Array[2])
{
}

template<typename Type>
inline CVectorReference3<Type>::CVectorReference3(const CVectorReference3<Type>& Vector) :
	m_x(Vector.m_x), m_y(Vector.m_y), m_z(Vector.m_z),
	m_s(Vector.m_s), m_t(Vector.m_t), m_p(Vector.m_p),
	m_r(Vector.m_r), m_g(Vector.m_g), m_b(Vector.m_b)
{
}

template<typename Type>
inline double CVectorReference3<Type>::GetLength(void) {
	double Size = ((double)m_x * m_x + m_y * m_y + m_z * m_z);
	return sqrt(Size);
}

template<typename Type>
template<typename InputType>
inline CVectorReference3<Type>& CVectorReference3<Type>::Set(const InputType x, const InputType y, const InputType z) {
	m_x = (Type)x;
	m_y = (Type)y;
	m_z = (Type)z;
	return *this;
}

template<typename Type>
template<typename InputType>
inline CVectorReference3<Type>& CVectorReference3<Type>::Set(const InputType* Array) {
	if (Array == nullptr) {
		m_x = 0; m_y = 0; m_z = 0;
	} else {
		m_x = (Type)Array[0];
		m_y = (Type)Array[1];
		m_z = (Type)Array[2];
	}return *this;
}

template<typename Type>
template<typename InputType>
inline double CVectorReference3<Type>::Dot(const CVectorReference3<InputType>& Vector) {
	return (double)m_x * Vector.m_x + m_y * Vector.m_y + m_z * Vector.m_z;
}

template<typename Type>
template<typename InputType>
inline CVector3<Type> CVectorReference3<Type>::Cross(const CVectorReference3<InputType>& Vector) {
	double X, Y, Z;
	// 計算結果
	X = ((double)m_y * Vector.m_z - m_z * Vector.m_y);
	Y = ((double)m_z * Vector.m_x - m_x * Vector.m_z);
	Z = ((double)m_x * Vector.m_y - m_y * Vector.m_x);
	return CVector3<Type>(X, Y, Z);
}

template<typename Type>
template<typename InputType>
inline void CVectorReference3<Type>::Swap(CVectorReference3<InputType>& Vector) {
	// 複製 Vector 的值
	CVector3<InputType> Temp;
	Temp = Vector;
	Vector = *this;
	*this = Temp;
}

template<typename Type>
template<typename InputType>
inline double CVectorReference3<Type>::GetAngle(const CVectorReference3<InputType>& Vector) {
	return GetRadian(Vector) * Rad2Deg;
}

template<typename Type>
template<typename InputType>
inline double CVectorReference3<Type>::GetRadian(const CVectorReference3<InputType>& Vector) {
	CVector3<double> v0, v1;
	v0 = *this;
	v1 = Vector;
	double Length1 = v0.GetLength();
	double Length2 = v1.GetLength();
	double Length = Length1 * Length2;
	if (Length == 0)
		return 0;
	double Cos = max(-1.0, min(1.0, v0.Dot(v1) / Length));
	return acos(Cos);
}


template<typename Type>
inline CVector3<double> CVectorReference3<Type>::GetNormalize(void) {
	CVector3<double> v0;
	v0 = *this;
	double Length = v0.GetLength();
	if (Length == 0)
		return v0;
	return CVector3<double>((double)m_x / Length, (double)m_y / Length, (double)m_z / Length);
}

template<typename Type>
inline CVector3<double> CVectorReference3<Type>::GetReverse(void) {
	return CVector3<double>(-m_x, -m_y, -m_z);
}

template<typename Type>
inline CVectorReference3<Type>& CVectorReference3<Type>::Normalize(void) {
	double Length = GetLength();
	if (Length == 0)
		return *this;
	m_x = (Type)(m_x / Length); m_y = (Type)(m_y / Length); m_z = (Type)(m_z / Length);
	return *this;
}

template<typename Type>
inline CVectorReference3<Type>& CVectorReference3<Type>::Reverse(void) {
	m_x = -m_x; m_y = -m_y; m_z = -m_z;
	return *this;
}

template<typename Type>
inline bool CVectorReference3<Type>::IsZero(void) {
	double LengthPow2 = m_x * m_x + m_y * m_y + m_z * m_z;
	if (LengthPow2 > 0.000001)
		return false;
	return true;
}

template<typename Type>
template<typename InputType>
inline CVector3<Type> CVectorReference3<Type>::operator+(const CVectorReference3<InputType>& Vector) {
	return Add(Vector);
}

template<typename Type>
template<typename InputType>
inline CVector3<Type> CVectorReference3<Type>::operator-(const CVectorReference3<InputType>& Vector) {
	return Sub(Vector);
}

template<typename Type>
inline CVector3<Type> CVectorReference3<Type>::operator*(const double Value) {
	return Mul(Value);
}

template<typename Type>
template<typename InputType>
inline CVector3<Type> CVectorReference3<Type>::operator*(const CVectorReference3<InputType>& Vector) {
	return Mul(Vector);
}

template<typename Type>
inline CVector3<Type> CVectorReference3<Type>::operator/(const double Value) {
	return Div(Value);
}

template<typename Type>
template<typename InputType>
inline CVector3<Type> CVectorReference3<Type>::operator/(const CVectorReference3<InputType>& Vector) {
	return Div(Vector);
}

template<typename Type>
template<typename InputType>
inline CVector3<Type> CVectorReference3<Type>::operator^(const CVectorReference3<InputType>& Vector) {
	return Cross(Vector);
}

template<typename Type>
inline CVectorReference3<Type>& CVectorReference3<Type>::operator=(const CVectorReference3<float>& Vector) {
	Assign(Vector);
	return *this;
}

template<typename Type>
inline CVectorReference3<Type>& CVectorReference3<Type>::operator=(const CVectorReference3<double>& Vector) {
	Assign(Vector);
	return *this;
}

template<typename Type>
template<typename InputType>
inline CVectorReference3<Type>& CVectorReference3<Type>::operator+=(const CVectorReference3<InputType>& Vector) {
	AddAssign(Vector);
	return *this;
}

template<typename Type>
template<typename InputType>
inline CVectorReference3<Type>& CVectorReference3<Type>::operator-=(const CVectorReference3<InputType>& Vector) {
	SubAssign(Vector);
	return *this;
}

template<typename Type>
inline CVectorReference3<Type>& CVectorReference3<Type>::operator*=(const double Value) {
	MulAssign(Value);
	return *this;
}

template<typename Type>
template<typename InputType>
inline CVectorReference3<Type>& CVectorReference3<Type>::operator*=(const CVectorReference3<InputType>& Vector) {
	MulAssign(Vector);
	return *this;
}

template<typename Type>
inline CVectorReference3<Type>& CVectorReference3<Type>::operator/=(const double Value) {
	DivAssign(Value);
	return *this;
}

template<typename Type>
template<typename InputType>
inline CVectorReference3<Type>& CVectorReference3<Type>::operator/=(const CVectorReference3<InputType>& Vector) {
	DivAssign(Vector);
	return *this;
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference3<Type>::operator==(const CVectorReference3<InputType>& Vector) {
	return Equal(Vector);
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference3<Type>::operator!=(const CVectorReference3<InputType>& Vector) {
	return !Equal(Vector);
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference3<Type>::operator>(const CVectorReference3<InputType>& Vector) {
	return Great(Vector);
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference3<Type>::operator<(const CVectorReference3<InputType>& Vector) {
	return Less(Vector);
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference3<Type>::operator>=(const CVectorReference3<InputType>& Vector) {
	return GreatEqual(Vector);
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference3<Type>::operator<=(const CVectorReference3<InputType>& Vector) {
	return LessEqual(Vector);
}

template<typename Type>
template<typename InputType>
inline CVector3<Type> CVectorReference3<Type>::Add(const CVectorReference3<InputType>& Vector) {
	return CVector3<Type>((Type)(m_x + Vector.m_x), (Type)(m_y + Vector.m_y), (Type)(m_z + Vector.m_z));
}

template<typename Type>
template<typename InputType>
inline CVector3<Type> CVectorReference3<Type>::Sub(const CVectorReference3<InputType>& Vector) {
	return CVector3<Type>((Type)(m_x - Vector.m_x), (Type)(m_y - Vector.m_y), (Type)(m_z - Vector.m_z));
}

template<typename Type>
inline CVector3<Type> CVectorReference3<Type>::Mul(const double Value) {
	return CVector3<Type>((Type)(m_x * Value), (Type)(m_y * Value), (Type)(m_z * Value));
}

template<typename Type>
template<typename InputType>
inline CVector3<Type> CVectorReference3<Type>::Mul(const CVectorReference3<InputType>& Vector) {
	return CVector3<Type>((Type)(m_x * Vector.m_x), (Type)(m_y * Vector.m_y), (Type)(m_z * Vector.m_z));
}

template<typename Type>
inline CVector3<Type> CVectorReference3<Type>::Div(const double Value) {
	if (Value == 0)
		return CVector3<Type>(*this);
	return CVector3<Type>((Type)(m_x / Value), (Type)(m_y / Value), (Type)(m_z / Value));
}

template<typename Type>
template<typename InputType>
inline CVector3<Type> CVectorReference3<Type>::Div(const CVectorReference3<InputType>& Vector) {
	if (Vector.m_x == 0.0 || Vector.m_y == 0.0 || Vector.m_z == 0.0)
		return CVector3<Type>(*this);
	return CVector3<Type>((Type)(m_x / Vector.m_x), (Type)(m_y / Vector.m_y), (Type)(m_z / Vector.m_z));
}

template<typename Type>
template<typename InputType>
inline void CVectorReference3<Type>::Assign(const CVectorReference3<InputType>& Vector) {
	m_x = (Type)Vector.m_x;
	m_y = (Type)Vector.m_y;
	m_z = (Type)Vector.m_z;
}

template<typename Type>
template<typename InputType>
inline void CVectorReference3<Type>::AddAssign(const CVectorReference3<InputType>& Vector) {
	m_x = (Type)(m_x + Vector.m_x);
	m_y = (Type)(m_y + Vector.m_y);
	m_z = (Type)(m_z + Vector.m_z);
}

template<typename Type>
template<typename InputType>
inline void CVectorReference3<Type>::SubAssign(const CVectorReference3<InputType>& Vector) {
	m_x = (Type)(m_x - Vector.m_x);
	m_y = (Type)(m_y - Vector.m_y);
	m_z = (Type)(m_z - Vector.m_z);
}

template<typename Type>
inline void CVectorReference3<Type>::MulAssign(const double Value) {
	m_x = (Type)(m_x * Value);
	m_y = (Type)(m_y * Value);
	m_z = (Type)(m_z * Value);
}

template<typename Type>
template<typename InputType>
inline void CVectorReference3<Type>::MulAssign(const CVectorReference3<InputType>& Vector) {
	m_x = (Type)(m_x * Vector.m_x);
	m_y = (Type)(m_y * Vector.m_y);
	m_z = (Type)(m_z * Vector.m_z);
}

template<typename Type>
inline void CVectorReference3<Type>::DivAssign(const double Value) {
	if (Value == 0)
		return;
	m_x = (Type)(m_x / Value);
	m_y = (Type)(m_y / Value);
	m_z = (Type)(m_z / Value);
}

template<typename Type>
template<typename InputType>
inline void CVectorReference3<Type>::DivAssign(const CVectorReference3<InputType>& Vector) {
	if (Vector.m_x == 0.0 || Vector.m_y == 0.0 || Vector.m_z == 0.0)
		return;
	m_x = (Type)(m_x / Vector.m_x);
	m_y = (Type)(m_y / Vector.m_y);
	m_z = (Type)(m_z / Vector.m_z);
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference3<Type>::Great(const CVectorReference3<InputType>& Vector) {
	if (m_x > Vector.m_x && m_y > Vector.m_y && m_z > Vector.m_z)
		return true;
	return false;
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference3<Type>::Less(const CVectorReference3<InputType>& Vector) {
	if (m_x < Vector.m_x && m_y < Vector.m_y && m_z < Vector.m_z)
		return true;
	return false;
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference3<Type>::Equal(const CVectorReference3<InputType>& Vector) {
	CVector3<Type> Temp((*this) - Vector);
	double LengthPow2 = Temp.m_x * Temp.m_x + Temp.m_y * Temp.m_y + Temp.m_z * Temp.m_z;
	if (LengthPow2 > 0.000001)
		return false;
	return true;
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference3<Type>::GreatEqual(const CVectorReference3<InputType>& Vector) {
	if (m_x >= Vector.m_x && m_y >= Vector.m_y && m_z >= Vector.m_z)
		return true;
	return false;
}

template<typename Type>
template<typename InputType>
inline bool CVectorReference3<Type>::LessEqual(const CVectorReference3<InputType>& Vector) {
	if (m_x <= Vector.m_x && m_y <= Vector.m_y && m_z <= Vector.m_z)
		return true;
	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////

template<typename Type>
inline CVector3<Type>::CVector3() :
	CVectorReference3<Type>(m_Buffer[0], m_Buffer[1], m_Buffer[2])
{
	m_Buffer[0] = 0;
	m_Buffer[1] = 0;
	m_Buffer[2] = 0;
}

template<typename Type>
template<typename InputType>
inline CVector3<Type>::CVector3(InputType Value0, InputType Value1, InputType Value2) :
	CVectorReference3<Type>(m_Buffer[0], m_Buffer[1], m_Buffer[2])
{
	m_Buffer[0] = (Type)Value0;
	m_Buffer[1] = (Type)Value1;
	m_Buffer[2] = (Type)Value2;
}

template<typename Type>
template<typename InputType>
inline CVector3<Type>::CVector3(InputType* Array) :
	CVectorReference3<Type>(m_Buffer[0], m_Buffer[1], m_Buffer[2])
{
	if (Array == nullptr) {
		m_Buffer[0] = 0;
		m_Buffer[1] = 0;
		m_Buffer[2] = 0;
	}
	else {
		m_Buffer[0] = (Type)Array[0];
		m_Buffer[1] = (Type)Array[1];
		m_Buffer[2] = (Type)Array[2];
	}
}



template<typename Type>
inline CVector3<Type>::CVector3(const CVectorReference2<Type>& Vector, Type z) :
	CVectorReference3<Type>(m_Buffer[0], m_Buffer[1], m_Buffer[2])
{
	m_Buffer[0] = (Type)Vector.m_x;
	m_Buffer[1] = (Type)Vector.m_y;
	m_Buffer[2] = (Type)z;
}

template<typename Type>
inline CVector3<Type>::CVector3(const CVector2<Type>& Vector, Type z) :
	CVectorReference3<Type>(m_Buffer[0], m_Buffer[1], m_Buffer[2])
{
	m_Buffer[0] = (Type)Vector.m_x;
	m_Buffer[1] = (Type)Vector.m_y;
	m_Buffer[2] = (Type)z;
}

template<typename Type>
inline CVector3<Type>::CVector3(const CVectorReference3<Type>& Vector) :
	CVectorReference3<Type>(m_Buffer[0], m_Buffer[1], m_Buffer[2])
{
	m_Buffer[0] = (Type)Vector.m_x;
	m_Buffer[1] = (Type)Vector.m_y;
	m_Buffer[2] = (Type)Vector.m_z;
}

template<typename Type>
inline CVector3<Type>::CVector3(const CVector3<Type>& Vector) :
	CVectorReference3<Type>(m_Buffer[0], m_Buffer[1], m_Buffer[2])
{
	m_Buffer[0] = (Type)Vector.m_x;
	m_Buffer[1] = (Type)Vector.m_y;
	m_Buffer[2] = (Type)Vector.m_z;
}
/*
template<typename Type>
template<typename InputType>
inline CVector3<Type> CVector3<Type>::operator+(const CVectorReference3<InputType>& Vector) {
	return CVectorReference3<Type>::Add(Vector);
}

template<typename Type>
template<typename InputType>
inline CVector3<Type> CVector3<Type>::operator-(const CVectorReference3<InputType>& Vector) {
	return CVectorReference3<Type>::Sub(Vector);
}

template<typename Type>
inline CVector3<Type> CVector3<Type>::operator*(const double Value) {
	return CVectorReference3<Type>::Mul(Value);
}

template<typename Type>
template<typename InputType>
inline CVector3<Type> CVector3<Type>::operator*(const CVectorReference3<InputType>& Vector) {
	return CVectorReference3<Type>::Mul(Vector);
}

template<typename Type>
inline CVector3<Type> CVector3<Type>::operator/(const double Value) {
	return CVectorReference3<Type>::Div(Value);
}

template<typename Type>
template<typename InputType>
inline CVector3<Type> CVector3<Type>::operator/(const CVectorReference3<InputType>& Vector) {
	return CVectorReference3<Type>::Div(Vector);
}
*/
template<typename Type>
inline CVectorReference3<Type>& CVector3<Type>::operator=(const CVectorReference3<float>& Vector) {
	CVectorReference3<Type>::Assign(Vector);
	return *this;
}

template<typename Type>
inline CVectorReference3<Type>& CVector3<Type>::operator=(const CVectorReference3<double>& Vector) {
	CVectorReference3<Type>::Assign(Vector);
	return *this;
}
/*
template<typename Type>
template<typename InputType>
inline CVectorReference3<Type>& CVector3<Type>::operator+=(const CVectorReference3<InputType>& Vector) {
	CVectorReference3<Type>::AddAssign(Vector);
	return *this;
}

template<typename Type>
template<typename InputType>
inline CVectorReference3<Type>& CVector3<Type>::operator-=(const CVectorReference3<InputType>& Vector) {
	CVectorReference3<Type>::SubAssign(Vector);
	return *this;
}

template<typename Type>
inline CVectorReference3<Type>& CVector3<Type>::operator*=(const double Value) {
	CVectorReference3<Type>::MulAssign(Value);
	return *this;
}

template<typename Type>
template<typename InputType>
inline CVectorReference3<Type>& CVector3<Type>::operator*=(const CVectorReference3<InputType>& Vector) {
	CVectorReference3<Type>::MulAssign(Vector);
	return *this;
}

template<typename Type>
inline CVectorReference3<Type>& CVector3<Type>::operator/=(const double Value) {
	CVectorReference3<Type>::DivAssign(Value);
	return *this;
}

template<typename Type>
template<typename InputType>
inline CVectorReference3<Type>& CVector3<Type>::operator/=(const CVectorReference3<InputType>& Vector) {
	CVectorReference3<Type>::DivAssign(Vector);
	return *this;
}

template<typename Type>
template<typename InputType>
inline bool CVector3<Type>::operator==(const CVectorReference3<InputType>& Vector) {
	return CVectorReference3<Type>::Equal(Vector);
}

template<typename Type>
template<typename InputType>
inline bool CVector3<Type>::operator!=(const CVectorReference3<InputType>& Vector) {
	return !CVectorReference3<Type>::Equal(Vector);
}

template<typename Type>
template<typename InputType>
inline bool CVector3<Type>::operator>(const CVectorReference3<InputType>& Vector) {
	return CVectorReference3<Type>::Great(Vector);
}

template<typename Type>
template<typename InputType>
inline bool CVector3<Type>::operator<(const CVectorReference3<InputType>& Vector) {
	return CVectorReference3<Type>::Less(Vector);
}

template<typename Type>
template<typename InputType>
inline bool CVector3<Type>::operator>=(const CVectorReference3<InputType>& Vector) {
	return CVectorReference3<Type>::GreatEqual(Vector);
}

template<typename Type>
template<typename InputType>
inline bool CVector3<Type>::operator<=(const CVectorReference3<InputType>& Vector) {
	return CVectorReference3<Type>::LessEqual(Vector);
}
*/
///////////////////////////////////////////////////////////////////////////////////////////

template<typename Type>
inline CMatrix3<Type>::CMatrix3() :
m_StackIndex(0)
{
	memcpy(m_Buffer, m_Identity, sizeof(m_Identity));
}

template<typename Type>
template<typename InputType>
inline CMatrix3<Type>::CMatrix3(InputType M00, InputType M01, InputType M02, InputType M10, InputType M11, InputType M12, InputType M20, InputType M21, InputType M22) :
	m_StackIndex(0) 
{
	_M00 = (Type)M00;	_M01 = (Type)M01;	_M02 = (Type)M02;
	_M10 = (Type)M10;	_M11 = (Type)M11;	_M12 = (Type)M12;
	_M20 = (Type)M20;	_M21 = (Type)M21;	_M22 = (Type)M22;
}

template<typename Type>
template<typename InputType>
inline CMatrix3<Type>::CMatrix3(InputType* Array) :
	m_StackIndex(0) 
{
	if (Array == nullptr) {
		memcpy(m_Buffer, m_Identity, sizeof(m_Identity));
	} else {
		// _Mxx = (Type) *Array 然後 Array 平移到下一個
		_M00 = (Type)*Array++; _M01 = (Type)*Array++; _M02 = (Type)*Array++;
		_M10 = (Type)*Array++; _M11 = (Type)*Array++; _M12 = (Type)*Array++;
		_M20 = (Type)*Array++; _M21 = (Type)*Array++; _M22 = (Type)*Array++;
	}
}

template<typename Type>
template<typename InputType>
inline CMatrix3<Type>::CMatrix3(CMatrix2<InputType>& Matrix) :
	m_StackIndex(0) 
{
	_M00 = (Type)Matrix._M00;	_M01 = (Type)Matrix._M01;	_M02 = 0;
	_M10 = (Type)Matrix._M10;	_M11 = (Type)Matrix._M11;	_M12 = 0;
	_M20 = 0;					_M21 = 0;					_M22 = 1;
}

template<typename Type>
template<typename InputType>
inline CMatrix3<Type>::CMatrix3(const CMatrix3<InputType>& Matrix) :
	m_StackIndex(0) 
{
	_M00 = (Type)Matrix._M00;	_M01 = (Type)Matrix._M01;	_M02 = (Type)Matrix._M02;
	_M10 = (Type)Matrix._M10;	_M11 = (Type)Matrix._M11;	_M12 = (Type)Matrix._M12;
	_M20 = (Type)Matrix._M20;	_M21 = (Type)Matrix._M21;	_M22 = (Type)Matrix._M22;
}

template<typename Type>
template<typename InputType>
inline CMatrix3<Type>& CMatrix3<Type>::SetMatrix(InputType* Array) {
	if (Array == nullptr) {
		memcpy(m_Buffer, m_Identity, sizeof(m_Identity));
	} else {
		Type* Buffer = m_Buffer;
		// _Mxx = (Type) *Array 然後 Array 平移到下一個
		_M00 = (Type)*Array++; _M01 = (Type)*Array++; _M02 = (Type)*Array++;
		_M10 = (Type)*Array++; _M11 = (Type)*Array++; _M12 = (Type)*Array++;
		_M20 = (Type)*Array++; _M21 = (Type)*Array++; _M22 = (Type)*Array++;
	}
	return *this;
}

template<typename Type>
inline Type* CMatrix3<Type>::GetBuffer(void) {
	return m_Buffer;
}

template<typename Type>
inline CMatrix3<Type> CMatrix3<Type>::GetInverse(void) {
	Type Det = (Type)GetDet();
	// 如果 Det = 0 代表沒有逆矩陣
	if (Det == 0) {
		return CMatrix3<Type>(	0, 0, 0,
								0, 0, 0,
								0, 0, 0);
	}
	return CMatrix3<Type>(	 (_M11 * _M22 - _M12 * _M21) / Det, -(_M01 * _M22 - _M21 * _M02) / Det, (_M01 * _M12 - _M11 * _M02) / Det,
							-(_M10 * _M22 - _M12 * _M20) / Det, (_M00 * _M22 - _M20 * _M02) / Det, -(_M00 * _M12 - _M10 * _M02) / Det,
							 (_M10 * _M21 - _M20 * _M11) / Det, -(_M00 * _M21 - _M20 * _M01) / Det, (_M00 * _M11 - _M01 * _M10) / Det);
}

template<typename Type>
inline CMatrix3<Type> CMatrix3<Type>::GetTranspose(void) {
	return CMatrix3<Type>(	_M00, _M10, _M20,
							_M01, _M11, _M21,
							_M02, _M12, _M22);
}

template<typename Type>
inline double CMatrix3<Type>::GetDet(void) {
	return (double)(	 _M00 * (_M11 * _M22 - _M21 * _M12)
						-_M01 * (_M10 * _M22 - _M20 * _M12)
						+_M02 * (_M10 * _M21 - _M20 * _M11));
}

template<typename Type>
inline CVectorReference3<Type> CMatrix3<Type>::GetRowVector(const int Index) {
	switch (Index) {
	case 0:
		return CVectorReference3<Type>(_M00, _M01, _M02);
	case 1:
		return CVectorReference3<Type>(_M10, _M11, _M12);
	case 2:
		return CVectorReference3<Type>(_M20, _M21, _M22);
	}
	return CVectorReference3<Type>(_M00, _M01, _M02);
}

template<typename Type>
inline CVectorReference3<Type> CMatrix3<Type>::GetColumnVector(const int Index) {
	switch (Index) {
	case 0:
		return CVectorReference3<Type>(_M00, _M10, _M20);
	case 1:
		return CVectorReference3<Type>(_M01, _M11, _M21);
	case 2:
		return CVectorReference3<Type>(_M02, _M12, _M22);
	}
	return CVectorReference3<Type>(_M00, _M10, _M20);
}

template<typename Type>
inline bool CMatrix3<Type>::WriteMatrix(char* FileName)
{
	if (FileName == nullptr)
		FileName = (char *)"Matrix.txt";
	ofstream Fout;
	Fout.open(FileName, ios::out);

	if (Fout.is_open() == 0)
		return false;

	Fout << "row: " << 3 << '\n';
	Fout << "column: " << 3 << '\n';
	Fout << _M00 << ' ' << _M01 << ' ' << _M02 << '\n';
	Fout << _M10 << ' ' << _M11 << ' ' << _M12 << '\n';
	Fout << _M20 << ' ' << _M21 << ' ' << _M22 << '\n';
	Fout.close();
	return true;
}

template<typename Type>
inline bool CMatrix3<Type>::ReadMatrix(char* FileName) {
	if (FileName == nullptr)
		FileName = (char *)"Matrix.txt";
	ifstream Fin;
	Fin.open(FileName, ios::in);
	if (Fin.is_open() == 0)
		return false;

	char Buf[16];
	int row, column;
	double m00, m01, m02;
	double m10, m11, m12;
	double m20, m21, m22;
	// 判斷關鍵字
	Fin >> Buf;
	if (strcmp(Buf, "row:") != 0)
		return false;
	// 讀入列數
	Fin >> row;

	// 判斷關鍵字
	Fin >> Buf;
	if (strcmp(Buf, "column:") != 0)
		return false;
	// 讀入行數
	Fin >> column;

	// 判斷格式
	if (row != 3 || column != 3)
		return false;

	Fin >> m00 >> m01 >> m02 >> m10 >> m11 >> m12 >> m20 >> m21 >> m22;
	_M00 = (Type)m00; _M01 = (Type)m01; _M02 = (Type)m02;
	_M10 = (Type)m10; _M11 = (Type)m11; _M12 = (Type)m12;
	_M20 = (Type)m20; _M21 = (Type)m21; _M22 = (Type)m22;
	Fin.close();
	return true;
}

template<typename Type>
inline CMatrix3<Type>& CMatrix3<Type>::PushMatrix(void) {
	// 應加入例外
	if (m_StackIndex < MATRIX_STACK_BUFFER_SIZE)
		memcpy(m_StackBuffer[m_StackIndex++], m_Buffer, sizeof(m_Buffer));
	return *this;
}

template<typename Type>
inline CMatrix3<Type>& CMatrix3<Type>::PopMatrix(void)
{
	if (m_StackIndex > 0)
		memcpy(m_Buffer, m_StackBuffer[--m_StackIndex], sizeof(m_Buffer));
	return *this;
}

#endif // !defined(Math_Module)