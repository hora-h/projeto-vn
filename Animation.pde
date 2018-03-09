class Animation{

    PImage[] sprite;
    int size;
    float rate, frame, x, y, w, h;

    Animation(String prefix, int size_, float rate_, float x_, float y_, float w_, float h_){

        size = size_;
        sprite = new PImage[size];
        rate = rate_;
        x = x_;
        y = y_;
        h = h_;
        w = w_;

        for (int i = 0; i < size; i++){
            String filename = prefix + i + ".png";
            sprite[i] = loadImage(filename);
        }
    }

    void display(){
        frame += rate;
        if(frame > size - 1){
            frame = 0;
        }
        imageMode(CORNER);
        image(sprite[int(frame)], x, y, h, w);
    }

}
