enum KinematicBodyType {
    SKATER, RAIL, BLOCK;
}

struct KinematicBody {
    unsigned int x, y;
    int v_x, v_y;
    int f_x, f_y;
    KinematicBodyType type;
    void * type_body;
    // use this to skip things for which collisions don't affect them, i.e. blocks
    // consider making this part of the type somehow, maybe a type_spec
    unsigned short self_collides;
    unsigned short collides_others;
}

(process_strategy*)(KinematicBody*) get_process_strategy(KinematicBodyType type);
(collision_strategy*)(KinematicBody*, KinematicBody*) get_collision_strategy(KinematicBodyType self_type, KinematicBodyType other_type);

/*

struct TypeMeta {
    KinematicBodyType type;
    collision_strategyies;
    self process strategy;
}

// loop through all TypeMeta and build arrays for lookup tables
/*
EXAMPLE:

for(int i = 0; i < size(kinematic_bodies); i++)
{
    if(kinematic_bodies[i]->self_collides)
    {
        for(int j = i; j < size(kinematic_bodies); j++)
        {
            if(kinematic_bodies[j]->collides_others)
            {
                // check collision
                if(collision)
                {
                    auto strat = get_collision_strategy(kinematic_bodies[i].type, kinematic_bodies[j].type);
                    strat(kinematic_bodies[i].type, kinematic_bodies[j].type);
                }
            }
        }
    }
}
*/