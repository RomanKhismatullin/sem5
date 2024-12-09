#pragma once
class TreeObj {

public:
	TreeObj(int NPrev, int N);

	/// <summary>
	/// Номер этого звена
	/// </summary>
	virtual int N() const final;
	/// <summary>
	/// Номер предыдущего звена	
	/// </summary>
	int NPrev() const;
	

protected:
	int _N;
	int _NPrev;
};
