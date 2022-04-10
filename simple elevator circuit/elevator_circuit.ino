int b = 1, a = 2, c = 3, d = 4, e = 5, f = 6, g = 7, sw1 = 10, sw2 = 9, sw3 = 8, lw1 = 11, lw2 = 12, lw3 = 13, mode = 0;
void setup()
{
    for (int i = 1; i <= 7; i++)
    {
        pinMode(i, OUTPUT);
    }
    pinMode(sw1, INPUT);
}
void one()
{
    digitalWrite(a, 0);
    digitalWrite(b, 1);
    digitalWrite(c, 1);
    digitalWrite(d, 0);
    digitalWrite(e, 0);
    digitalWrite(f, 0);
    digitalWrite(g, 0);
}
void two()
{
    digitalWrite(a, 1);
    digitalWrite(b, 1);
    digitalWrite(c, 0);
    digitalWrite(d, 1);
    digitalWrite(e, 1);
    digitalWrite(f, 0);
    digitalWrite(g, 1);
}
void three()
{
    digitalWrite(a, 1);
    digitalWrite(b, 1);
    digitalWrite(c, 1);
    digitalWrite(d, 1);
    digitalWrite(e, 0);
    digitalWrite(f, 0);
    digitalWrite(g, 1);
}
void loop()
{
    while (mode == 0)
    {
        digitalWrite(a, 1);
        digitalWrite(b, 1);
        digitalWrite(c, 1);
        digitalWrite(d, 1);
        digitalWrite(e, 1);
        digitalWrite(f, 1);
        digitalWrite(g, 0);
        while (digitalRead(sw1) == 1)
        {
            mode = 1;
        }
        while (digitalRead(sw2) == 1)
        {
            mode = 2;
        }
        while (digitalRead(sw3) == 1)
        {
            mode = 3;
        }
    }
    ///////////////////////////////////////////// /////////////////////////////////////////////////
    while (mode == 1)
    {
        while (digitalRead(lw1) == 1)
        {
            one();
        }
        while (digitalRead(sw2) == 1)
        {
            mode = 2;
        }
        while (digitalRead(sw3) == 1)
        {
            mode = 3;
        }
    }
    /////////////////////////////////////////////////
    while (mode == 2)
    {
        while (digitalRead(lw1) == 1)
        {
            one();
        }
        while (digitalRead(lw2) == 1)
        {
            two();
        }
        while (digitalRead(sw1) == 1)
        {
            mode = 1;
        }
        while (digitalRead(sw3) == 1)
        {
            mode = 3;
        }
    }
    /////////////////////////////////////////////////
    while (mode == 3)
    {
        while (digitalRead(lw1) == 1)
        {
            one();
        }
        while (digitalRead(lw2) == 1)
        {
            two();
        }
        while (digitalRead(lw3) == 1)
        {
            three();
        }
        while (digitalRead(sw1) == 1)
        {
            mode = 4;
        }
        while (digitalRead(sw2) == 1)
        {
            mode = 5;
        }
    }
    while (mode == 4)
    {
        while (digitalRead(lw2) == 1)
        {
            two();
        }
        while (digitalRead(lw1) == 1)
        {
            one();
        }
    }
    while (mode == 5)
    {
        while (digitalRead(lw2) == 1)
        {
            two();
        }
        while (digitalRead(sw1) == 1)
        {
            mode = 1;
        }
    }
}