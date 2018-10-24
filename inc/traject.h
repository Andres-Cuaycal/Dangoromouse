#ifndef MY_DOT_H
#define MY_DOT_H
typedef struct{
  float x;
  float y;
  float rad;
}dotData;
class Traject{
  private:
    std::vector<dotData> data;
    Operation::OperationType turn_type;
    float offset_straight;
    uint32_t data_size;
  public:
    Traject(): data(200), data_size(0){}
    Traject(Operation::OperationType type): data(200), turn_type(type), data_size(0){}
    void static_push_back(float y, float x, float rad);
    void static_push_back(dotData dot);
    void set_dot();
    inline dotData get_data(uint32_t index){return data[index];}
    dotData get_data(uint32_t index, Operation::OperationType type);
    dotData reverse_get_data(uint32_t index, Operation::OperationType type);
    dotData end(Operation::OperationType typical){return get_data(data_size - 1, typical);}
    size_t virtual_size(){return data.size();}
    size_t real_size(){return data_size;}
    inline void set_offset(float offset){offset_straight = offset;}
    float get_offset(){return offset_straight;}
    inline Operation::OperationType get_type(){return turn_type;}
};
class TrajectList{
  private:
    std::vector<Traject> v90List;
    std::vector<Traject> turn135List;
    std::vector<Traject> turn45List;
  public:
    TrajectList(): v90List(4), turn135List(4), turn45List(4){}
    Traject getTraject(Operation::OperationType type, Direction direction);
    //void setTraject(Traject turn45, Traject turn135, Traject V90);
    void setTraject(Traject traject);
};
extern Traject turn45;
extern Traject turn135;
extern Traject v90;
extern TrajectList trajectList;
void set_traject();
#endif
