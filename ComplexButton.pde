class ComplexButton{

    int tipo;
    float x, y, h, w;
    PImage[] imgs;

    ComplexButton(String fileprefix, float x_, float y_, float w_, float h_, int t_){
        tipo = t_;
        x = x_;
        y = y_;
        h = h_;
        w = w_;
        for(int i = 0; i < 2; i++){
            imgs[i] = loadImage(fileprefix + 1 + ".png");
        }
    }

    void display(){
        if(tipo == 1){
            imageMode(CORNER);
            image(imgs[1], x, y, w, h);
        }else{
            imageMode(CENTER);
            image(imgs[1], x, y, h, h);
        }
    }

    boolean mouseCheck(){

        if(tipo == 1){
            if(mouseX >= x && mouseX <= x+w && mouseY >= y && mouseY <= y+h){
                imageMode(CORNER);
                image(imgs[2], x, y, w, h);
                if(mousePressed){
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }else{
            if(dist(mouseX, mouseY, x, y) <= h/2){
                imageMode(CENTER);
                image(imgs[2], x, y, h, h);
                if(mousePressed){
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }

    }

}
