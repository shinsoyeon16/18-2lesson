#pragma once
struct Location2D {//��ǥǥ���� ���� Ŭ����
	int row;
	int col;
	Location2D(int r = 0, int c = 0) { row = r; col = c; }//������

	//bool isNeighbor(Location2D&p)//�����ִ� ���� Ȯ���ϴ°� 
	//{
	//	return ((row == p.row && (col == p.col - 1 || col == p.col + 1))
	//		|| (col==p.col&&(col == p.row - 1 || row == p.row + 1)));
	//}
	//bool operator==(Location2D&p) { return row == p.row&& col == p.col; }
};
