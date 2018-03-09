void settings(){
    fullScreen();
    size(1024, 768);
    smooth(8);
}

SimpleDialogBox test;

void setup(){
    test  = new SimpleDialogBox("bg.png", "PressStart2P.ttf", 5, 300, 500, 700, 150);
    test.tw = 500;
    test.tx = test.x + 10;
    test.txts[0] = "Essa porra desse processing é um caralho \n(qualquer tecla para next)";
    test.txts[1] = "Ficar fazendo texto de teste pra ver se estora a porra da caixa de texto tambem é uma porra";
    test.txts[2] = "Seria muito legal se alguem fizesse um parser pra essa porra ";
    test.txts[3] = "O teste de alocação tambem é legal, eu aloquei cinco textos, logo a caixa vai existir cinco vezes, mas ja que nao tem texto, ela vai mostrar nada";
}

void draw(){
    background(0);
    test.display();
}
