#pragma once
class TreeObj {

public:
	TreeObj(int NPrev, int N);

	/// <summary>
	/// ����� ����� �����
	/// </summary>
	virtual int N() const final;
	/// <summary>
	/// ����� ����������� �����	
	/// </summary>
	int NPrev() const;
	

protected:
	int _N;
	int _NPrev;
};
