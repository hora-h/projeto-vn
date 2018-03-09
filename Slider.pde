class Slider{

    float x, y, w, bx, vl, vlmax, vlmin;

    Slider(float x_, float y_, float w_, float vl_, float vlmin_, float vlmax_){

        x = x_;
        y = y_;
        w = w_;
        vl = vl_;
        vlmax = vlmax_;
        vlmin = vlmin_;
        bx = map(vl, vlmin, vlmax, x, x+w);

    }

    void display(){

        stroke(255);
        strokeWeight(4);
        line(x, y, bx, y);
        stroke(255);
        strokeWeight(1);
        line(bx, y, x+w, y);
        fill(255);
        noStroke();
        ellipse(bx, y, 50, 50);

    }

    float slide(){

        if(dist(mouseX, mouseY, bx, y) < 25){
            if(mousePressed){
                bx = constrain(mouseX, x, x+w);
            }
        }

        vl = map(bx, x, x+w, vlmin, vlmax);
        return vl;

    }

}
