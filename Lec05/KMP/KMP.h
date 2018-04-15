#ifndef KMP_H
#define KMP_H


class KMP
{
    public:
        KMP(int _TextSize, int _PatternSize);
        ~KMP();

        int stringCompare(); // if found , return position ; else return -1
    private:
        char *Text;
        char *Pattern;
};

#endif // KMP_H
