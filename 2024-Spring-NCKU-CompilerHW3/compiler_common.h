#ifndef COMPILER_COMMON_H
#define COMPILER_COMMON_H

#include <stdbool.h>
#include <stdint.h>

#define getBool(val) (*(int8_t*)&((val)->value))
#define getByte(val) (*(int8_t*)&((val)->value))
#define getChar(val) (*(int8_t*)&((val)->value))
#define getShort(val) (*(int16_t*)&((val)->value))
#define getInt(val) (*(int32_t*)&((val)->value))
#define getLong(val) (*(int64_t*)&((val)->value))
#define getFloat(val) (*(float*)&((val)->value))
#define getDouble(val) (*(double*)&((val)->value))
#define getString(val) (*(char**)&((val)->value))

#define asVal(val) (*(int64_t*)&(val))

typedef enum _objectType {
    OBJECT_TYPE_UNDEFINED,
    OBJECT_TYPE_AUTO,
    OBJECT_TYPE_VOID,
    OBJECT_TYPE_BOOL,
    OBJECT_TYPE_BYTE,
    OBJECT_TYPE_CHAR,
    OBJECT_TYPE_SHORT,
    OBJECT_TYPE_INT,
    OBJECT_TYPE_LONG,
    OBJECT_TYPE_FLOAT,
    OBJECT_TYPE_DOUBLE,
    OBJECT_TYPE_STR,
    OBJECT_TYPE_FUNCTION,
} ObjectType;

typedef struct _symbolData {
    char* name;
    int32_t index;
    int64_t addr;
    int32_t lineno;
    char* func_sig;
    uint8_t func_var;
} SymbolData;

typedef struct _arrayType {
  int length; // Array length
  int twoDSize;
  int elements[100]; // Pointer to the array elements
} ArrayType;

typedef struct _object {
    ObjectType type;
    union {
        int int_value;
        float float_value;
        bool bool_value;
        char* str_value;
        char char_value;
        ArrayType array_value;
        ObjectType funcType;
    } value;
    uint8_t flag;   
    uint32_t array;     
    SymbolData* symbol;
} Object;

extern int yylineno;
extern int funcLineNo;

#endif /* COMPILER_COMMON_H */