#pragma once
#include <iostream>
#include <stdexcept>

template<class T>
class Vector{
private:
  T* m_data;
  size_t m_size;
  size_t m_capacity;

  // Modifiers
  void resize();
  
public:
  // Constructors
  Vector();
  Vector(size_t t_capacity);
  Vector(T t_array[], size_t t_capacity);
  // Modifiers
  void push_back(T t_data);
  void reserve(size_t t_capacity);
  void addEdge(int t_source, int t_destiny);
};

/**
*
*
*/
template<class T>
Vector<T>::Vector(){
  m_size = 0;
  m_capacity = 2;
  m_data = new T[m_capacity];
}

/**
*
*
*/
template<class T>
Vector<T>::Vector(size_t t_capacity){
  m_size = 0;
  m_capacity = t_capacity;
  m_data = new T[m_capacity];
}

/**
*
*
*/
template<class T>
Vector<T>::Vector(T t_array[], size_t t_capacity){
  m_size = t_capacity;
  m_capacity = m_size;
  m_data = new T[m_size];
  for(size_t i = 0; i < m_size; i++){
    m_data[i] = t_array[i];
    m_size++;
  }
}
    
/**
*
*
*/
template<class T>
void Vector<T>::push_back(T t_data){
  if(m_capacity == m_size){
    //resize();
  }
  if(!m_data){
    
  }
  m_data[m_size] = t_data;
  m_size++;
}

 /**
*
*
*/
template<class T>
void Vector<T>::resize(){
  reserve(m_capacity *= 2);
}

 /**
*
*
*/
template<class T>
void Vector<T>::reserve(size_t t_capacity){
  if(t_capacity < m_size){
    throw std::range_error("Invalid Capacity Value. Code: Mal uwu");
  }
  m_capacity = t_capacity;
  T* dataTemp = new T[m_size];
  for(size_t i = 0; i < m_size; i++){
    dataTemp[i] = m_data[i];
  }
  delete []m_data;
  m_data = new T[m_capacity];
  for(size_t i = 0; i < m_size; i++){
    m_data[i] = dataTemp[i];
  }

  std::cout<<"\nThe vector's capacity has been updated to: "<<m_capacity<<std::endl;
}


/**
*
*
*/
/*
template<class T>
void Vector<T>::addEdge(int t_source, int t_destiny){
  m_data.push_back(t_destiny);
  m_data.push_back(t_source);
}
*/
