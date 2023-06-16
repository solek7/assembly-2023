typedef enum error {
    NO_ERROR,
    ERROR_MISSING_VARIABLE,
    ERROR_UNDEFINED_VARIABLE,
    ERROR_UNDEFINED_COMMAND,
    ERROR_MISSING_COMMA,
    ERROR_ILLEGAL_COMMA,
    ERROR_EXTRANEOS_TEXT,
    ERROR_MAXED_OUT_LINE_LENGTH,
    ERROR_NO_MEMORY,
    ERROR_WRONG_ARGUMENT_FORMAT
} Error;