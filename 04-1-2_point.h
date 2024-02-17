#ifndef __POINT_H_
#define __POINT_H_

class Point {
  // information hiding
  // member var -> private
  // getter, setter -> public(access function)
private:
  int x;
  int y;

public:
  bool InitMembers(int xpos, int ypos);
  Point(const int &xpos, const int &ypos); // constructor
  int GetX() const;
  int GetY() const;
  bool SetX(int xpos);
  bool SetY(int ypos);
};

#endif