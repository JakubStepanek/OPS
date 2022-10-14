#include "mbed.h"
#include <string>

DigitalOut myled(LED1);
double dotTime = 0.2;
double dashTime = 0.6;
double symbolSpaceTime = 1.0;
double letterSpaceTime = 2.0;
double wordSpaceTime = 4.0;

void dot(int rep) {
  for (int i = 0; i < rep; i++) {
    myled = 1;
    wait(dotTime);
    myled = 0;
    wait(symbolSpaceTime);
  }
}

void dash(int rep) {
  for (int i = 0; i < rep; i++) {
    myled = 1;
    wait(dashTime);
    myled = 0;
    wait(symbolSpaceTime);
  }
}

void letterSpace() { wait(letterSpaceTime); }

void wordSpace() { wait(wordSpaceTime); }

void akat() {
  dot(1);
  dash(1);
}

void blyskavice() {
  dash(1);
  dot(3);
}
void cilovnik() {
  dash(1);
  dot(1);
  dash(1);
  dot(1);
}

void dalava() {
  dash(1);
  dot(2);
}

void erb() { dot(1); }

void filipiny()
{
    dot(2);
    dash(1);
    dot(1);
}

void gronskaZem()
{
    dash(2);
    dot(1);
}

void hrachovina()
{
    dot(4);
}

void ibis() { dot(2); }

void jasminBily()
{
    dot(1);
    dash(3);
}

void krakora()
{
    dash(1);
    dot(1);
    dash(1);
}

void lupinecek() {
  dot(1);
  dash(1);
  dot(2);
}

void mava()
{
    dash(2);
}

void nastup()
{
    dash(1);
    dot(1);
}

void oNasPan() { dash(3); }

void papirnici()
{
    dot(1);
    dash(2);
    dot(1);
}

void kviliOrkan()
{
    dash(2);
    dot(1);
    dash(1);
}

void rarasek()
{
    dot(1);
    dash(1);
    dot(1);
}

void sobota() { dot(3); }
void tram()
{
    dash(1);
}

void ulicnik() {
  dot(2);
  dash(1);
}

void vyuceny()
{
    dot(3);
    dash(1);
}

void vagonKlad()
{
    dot(1);
    dash(2);
}

void xeroklates()
{
    dash(1);
    dot(2);
    dash(1);
}

void ygarMava()
{
    dash(1);
    dot(1);
    dash(2);
}

void znamaZena()
{
    dash(2);
    dot(1);
}


int main() {
  while (1) {
    lupinecek();
    ulicnik();
    cilovnik();
    ibis();
    erb();
    wordSpace();
  }
}
