#ifndef CommandBuffer_h
#define CommandBuffer_h

#include <Arduino.h>
#include <inttypes.h>
#include "Command.h"

class CommandBuffer{
private:
   char * _buffer;
   const uint16_t _len;
   bool _buffer_overflow;
   uint16_t _endOffset;

   volatile uint8_t _readOffset;

   int nextEndOffSet();
   bool isListEnd(char c);
    int peekNextDigit();

public:
  // public methods
  CommandBuffer(char *buffer, const uint16_t len, bool clean = true);
  ~CommandBuffer() {}

  operator const char *() const { return _buffer; }

  const uint16_t current_length() const { return _endOffset; }

  bool overflow() { return _buffer_overflow; }

  virtual size_t write(uint8_t byte);
  virtual int peek();
  virtual int read();
  virtual int available();
  virtual void flush();


  long parseInt(); // returns the first valid (long) integer value from the current position.

  // initial characters that are not digits (or the minus sign) are skipped
   // integer is terminated by the first character that is not a digit.

  float parseFloat();               // float version of parseInt

  long parseInt(char skipChar); // as above but the given skipChar is ignored
   // as above but the given skipChar is ignored
   // this allows format characters (typically commas) in values to be ignored

  float parseFloat(char skipChar);  // as above but the given skipChar is ignored

  String readString();
  int readLongValues(long values[], int max);
  int readIntValues(int values[], int max);
  int readFloatValues(float values[], int max);

  int getReadOffset(){ return _readOffset; };
};

#endif
