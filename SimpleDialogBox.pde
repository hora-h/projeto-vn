class SimpleDialogBox{

    float x, y, yd, a, yi, h, w, tx, ty, th, tw;
    int j, size, delay, fsize = 12;
    color txtc;
    PFont txtf;
    PImage bg;
    String[] txts;


    SimpleDialogBox(String file, String fontfile, int size_, float x_, float y_, float w_, float h_){
        size = size_;
        a = 0;
        tx = x = x_;
        ty = y = y_;
        th = h = h_;
        tw = w = w_;
        yi = y_;
        yd = 0.5;
        j = 0;
        delay = 60;
        txts = new String[size];
        txtf = createFont(fontfile, 14);

        for(int i = 0; i < size; i++){
            txts[i] = new String();
        }

        bg = loadImage(file);
    }

    void display(){

        a += 35;
        y -= yd;
        yd += 0.2;

        if(y <= yi-10){
            y = yi-10;
        }

        image(bg, x, y, w, h);
        textFont(txtf);
        text(txts[j], tx, ty, tw, th);

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
