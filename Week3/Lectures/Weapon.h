#pragma once
class Weapon
{
private:
	//
	// FIELDS (data members)
	//   what describes the object
	//	 make them private
	//	 naming convention:
	//		camelCasingNamingConvention
	//		ex:
	//		  m_iRange, mRange, m_range, _range, range_
	int mRange;
	int mDamage;

	//void DoIt(int range)
	//{
	//	int range = 10;
	//	mRange = range;
	//}

public:
	// constructors (ctors)
	//   initialize the object when you create it
	//   MUST be named the same as the class
	//   CANNOT have a return type (not even void)
	// 
	//	 IF you do NOT create a CTOR, 
	//		the compiler gives you a default ctor
	//		a default ctor has NO parameters
	//   IF you do create a CTOR,
	//		the compiler's ctor is no longer created
	// 
	Weapon(int range, int damage);

	virtual void showMe();
	int calcDamage();

	// Gatekeepers to the fields
	//   the definitions can appear in the header
	// 
	// getters (accessors)
	//	return type matches the type of the field
	//	usually are const b/c they should not modify the field
	//	no parameters
	//  Naming:
	//     GetFieldName or FieldName
	//
	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}

	//
	// setters (mutators)
	//	void return type
	//	non-const b/c it should change the field
	//  at least 1 parameter to change the field
	//		usually the type matches the field
	//	can have validation logic
	//	Naming:
	//		SetFieldName or FieldName
	void SetRange(int range)
	{
		//validate the parameter
		if (range > 0)
		{
			mRange = range;
		}
	}

	void Damage(int damage)
	{
		if (damage > 0 && damage < 1000)
		{
			mDamage = damage;
		}
	}
};

