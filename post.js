
var NULL = Module['NULL'];

function vector3_set_x(vec3, x) {
    return FclHelper.prototype['vector3_set_x'].call(NULL, vec3, x);
}

function vector3_set_y(vec3, y) {
    return FclHelper.prototype['vector3_set_y'].call(NULL, vec3, y);
}

function vector3_set_z(vec3, z) {
    return FclHelper.prototype['vector3_set_z'].call(NULL, vec3, z);
}

function vector3_set_values(vec3, x, y, z) {
    return FclHelper.prototype['vector3_set_values'].call(NULL, vec3, x, y, z);
}

Module["vector3_set_x"] = vector3_set_x;
Module["vector3_set_y"] = vector3_set_y;
Module["vector3_set_z"] = vector3_set_z;
Module["vector3_set_values"] = vector3_set_values;
