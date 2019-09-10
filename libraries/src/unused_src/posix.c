#include "posix.h"
uint8_t posix_ishexletter(uint8_t ch)
{
    if((ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F')) {
        return 1;
    }
    else
    {
        return 0;
    }
}

posix_token* posix_tknch(const char *str)
{
    uint8_t str_length = strlen(str);
    uint8_t index;
    posix_token *ptkn_ch = (posix_token *)malloc(str_length*sizeof(posix_token));
    for(index = 0; index < str_length; index++)
    {
        if(str[index] >= 'a' && str[index] <= 'z') {
            ptkn_ch[index].tkn_class = lower;
        } else if(str[index] >= 'A' && str[index] <= 'Z') {
            ptkn_ch[index].tkn_class = upper;
        } else if(str[index] >= '0' && str[index] <= '9') {
            ptkn_ch[index].tkn_class = digit;
        } else if(str[index] >= '!' && str[index] <= '/') {
            ptkn_ch[index].tkn_class = punct;
        } else if(str[index] >= '[' && str[index] <= '`') {
            ptkn_ch[index].tkn_class = punct;
        } else if(str[index] >= '{' && str[index] <= '~') {
            ptkn_ch[index].tkn_class = punct;
        } else if(str[index] >= ':' && str[index] <= '@') {
            ptkn_ch[index].tkn_class = punct;
        } else if(str[index] == 0x20) {
            ptkn_ch[index].tkn_class = space;
        } else if(str[index] >= 0x09 && str[index] <= 0x0d) {
            ptkn_ch[index].tkn_class = space;
        } else if(str[index] >= 0x00 && str[index] <= 0x1f) {
            ptkn_ch[index].tkn_class = cntrl;
        } else if(str[index] == 0x7f) {
            ptkn_ch[index].tkn_class = cntrl;
        }
        ptkn_ch[index].tkn_value = str[index];
    } 
    
    return ptkn_ch;
}
posix_token* posix_tokenizer(const char *str)
{
    uint8_t str_length = strlen(str);
    uint8_t index;
    posix_token *ptkn_ch = posix_tknch(str);
    posix_token *ptkn_word = (posix_token *)malloc(sizeof(posix_token));
    ptkn_word->tkn_str = (char *)calloc(sizeof(char),TKN_STR_LEN);
    posix_character_class state = tknmax;
    
    for(index = 0; index < str_length; index++)
    {
        switch(state)
        {
            case tknmax: // init;
                switch(ptkn_ch[index].tkn_class) {
                    case upper: state = upper;  break;
                    case lower: state = lower;  break;
                    case digit: state = digit;  break;
                    default: break;
                }
                break;
            case upper:
                switch(ptkn_ch[index].tkn_class) {
                    case upper: state = upper;  break;
                    case lower: state = alpha;  break;
                    case digit: state = alnum;  break;
                    default: break;
                }
                break;
            case lower:
                switch(ptkn_ch[index].tkn_class) {
                    case upper: state = alpha;  break;
                    case lower: state = lower;  break;
                    case digit: state = alnum;  break;
                    default: break;
                }
                break;
            case alpha:
                switch(ptkn_ch[index].tkn_class) {
                    case digit: state = alnum;  break;
                    default: break;
                }
                break;
            case alnum:
                break;
            case digit:
                switch(ptkn_ch[index].tkn_class) {
                    case lower: 
                    case upper:  
                        if (posix_ishexletter(ptkn_ch[index].tkn_value)) {
                            state = xdigit;
                        } else {
                            state = alnum;
                        }
                        break;
                    default: break;
                }
                break;
            case xdigit:
                switch(ptkn_ch[index].tkn_class) {
                    case lower: 
                    case upper:
                        if(!posix_ishexletter(ptkn_ch[index].tkn_value)) {  
                                state = alnum;  
                        }
                        break;
                    default: break;
                }
                break;
            default:
                break;
        }
    } 
    ptkn_word->tkn_class = state;
    strcpy(ptkn_word->tkn_str,str);
    free(ptkn_ch);
    return ptkn_word;
}

