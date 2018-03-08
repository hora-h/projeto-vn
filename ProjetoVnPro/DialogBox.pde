class DialogBox{

    float x, y, yd, a, yi, h, w;
    int j, size, delay;
    color txtc;
    PImage[] imgs;


    DialogBox(String fileprefix, int size_, float x_, float y_, float w_, float h_){
        size = size_;
        a = 0;
        x = x_;
        y = y_;
        h = h_;
        w = w_;
        yi = y_;
        yd = 0.5;
        j = 0;
        delay = 60;
        for(int i = 0; i < size; i++){
            imgs[i] = loadImage(fileprefix + i + ".png");
        }
    }

    void display(){

        a += 35;
        y -= yd;
        yd += 0.2;

        if(y <= yi-10){
            y = yi-10;
        }

        image(imgs[j], x, y, w, h);

        if(keyPressed && delay > 60 && j < size){
            j++;
            a = 0;
            y = yi;
            yd = 0.5;
            delay = 0;
        }

        delay++;
    }

}
