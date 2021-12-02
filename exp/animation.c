struct AnimationCell {
    const unsigned int duration;
    const unsigned int tile_number;
    AnimationCell * next_cell;
}

struct PlayingAnimation {
    unsigned int remaining_duration;
    AnimationCell * cell;
}



play_cells(PlayingAnimation * all_animations, unsigned int num_animtaions)
{
    for(int i = 0; i < num_animations; i++)
    {   
        PlayingAnimation * anim = all_animations + i*sizeof(PlayingAnimation); // or something
        if(anim->remaining_duration == 0)
        {
            anim->cell = anim->cell->next_cell;
            anim->remaining_duration = anim->cell->duration;
            // set the tile cell
        } else {
            anim->remaining_duration--;
        }       
    }
}