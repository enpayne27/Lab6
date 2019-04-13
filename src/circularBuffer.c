#include "circularBuffer.h"

//Iniitialize the struct commBuffer_t to zero
void initBuffer(commBuffer_t* comm, uint8_t type){
    comm -> head = 0;
    comm -> tail = 0;
    comm -> buffer = "";
    comm -> type = 0;
    comm -> MessageCount = 0;
    comm -> bufferSize = 0;
    comm -> type = type;
}

//Test if a complete message is in buffer delimiter is '\n'
//Read only, checking MessageCount - doesn't matter how many, just if one is there
uint8_t haveMessage(commBuffer_t* comm){
  //If MessageCount == 0 (false) || == 1 (true) then return
  if(comm -> MessageCount) return 1;
  else return 0;
}

//Put character in buffer and update head - focused on Tx
//Using haveMessage - could check for delimiter here and change MessageCount
void putChar(commBuffer_t* comm, char ch){
  //Handle delimiter (translate into null character)
  if(ch == '\n'){
    ch = '\0';
    comm -> MessageCount += 1;
  }
  //Check if head does not exceed maximum buffer size
  if(comm -> head <= MAXCOMMBUFFER - 1){
    comm -> buffer[comm -> head] = ch;
    comm -> head += 1;
    ++bufferSize;
  }
  //If so, return to start and then put character in buffer
  else{
    comm -> buffer[comm -> head] = ch;
    comm -> head = 0;
    ++bufferSize;
  }
}

//********************TODO********************************
//Get character from buffer and update tail - focused Rx
char getChar(commBuffer_t* comm){
  //Handle delimiter (translate into newline)
  if(ch == '\0'){
    ch = '\n';
    comm -> MessageCount -= 1;
  }
  //Check if head does not exceed maximum buffer size
  if(comm -> tail <= MAXCOMMBUFFER - 1){
    comm -> buffer[comm -> tail] = ch;
    comm -> tail += 1;
    --bufferSize;
  }
  //If so, return to start and then put character in buffer
  else{
    comm -> buffer[comm -> tail] = ch;
    comm -> tail = 0;
    --bufferSize;
  }
}

//put C string into buffer
void putMessage(commBuffer_t* comm, char* str, uint8_t length){
  //Always incrementing MessageCount
  //Utilize putChar

  --bufferSize;
}

//get C string from buffer
void getMessage(commBuffer_t* comm, char* str){
  //Always decrementing MessageCount
  //Utilize getChar
}

//get Size of Buffer
int getBufferSize(commBuffer_t* comm){
  //(head-tail+maxSize) % maxSize
  return comm -> bufferSize;
}
