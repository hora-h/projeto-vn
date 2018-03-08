class SimpleButton{

    int tipo;
    float x, y, h, w, ar;
    PImage img;

    SimpleButton(String imgfile, float x_, float y_, float w_, float h_, int t_, float ar_){
        tipo = t_;
        x = x_;
        y = y_;
        h = h_;
        w = w_;
        ar = ar_;
        img = loadImage(imgfile);
    }

    void display(){

        if(tipo == 1){
            imageMode(CORNER);
            image(img, x, y, w, h);
        }else{
            imageMode(CENTER);
            image(img, x, y, h, h);
        }

    }

    boolean mouseCheck(){

        if(tipo == 1){
            if(mouseX >= x && mouseX <= x+w && mouseY >= y && mouseY <= y+h){
                fill(100, 100, 100, 100);
                noStroke();
                rectMode(CORNER);
                rect(x, y, w, h, ar);
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
                fill(100, 100, 100, 100);
                noStroke();
                ellipseMode(CENTER);
                ellipse(x, y, h, h);
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
