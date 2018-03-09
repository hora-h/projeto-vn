class WireframeButton{

    float x, y, h, w;

    WireframeButton(float x_, float y_, float w_, float h_){
        x = x_;
        y = y_;
        h = h_;
        w = w_;
    }

    void display(){
        noFill();
        strokeWeight(3);
        stroke(255);
        rectMode(CORNER);
        rect(x, y, w, h);
        line(x, y, x+w, y+h);
        line(x+w, y, x, y+h);
    }

    boolean mouseCheck(){
        if(mouseX >= x && mouseX <= x+w && mouseY >= y && mouseY <= y+h){
            fill(100, 100, 100, 100);
            noStroke();
            rectMode(CORNER);
            rect(x, y, w, h);
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
