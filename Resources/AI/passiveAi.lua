dofile("./Resources/AI/global.lua")
dofile("./Resources/AI/utils.lua")
dofile("./Resources/AI/danger_dir.lua")
dofile("./Resources/AI/construct_map.lua")
dofile("./Resources/AI/directions.lua")
dofile("./Resources/AI/best_first.lua")
dofile("./Resources/AI/actions.lua")
dofile("./Resources/AI/shortest_priority.lua")

function launch_passive()
	local entities = get_entities()
	local map = create_map(entities, AGGRO)
	if (map == nil) then return -1 end
	-- display_map(map)
 	local cur_x, cur_y = random_movement(map)
	return determine_way(map, cur_x, cur_y)
end

TYPE_PRIORITY = {
	["player"] = 1,
	["item"] = 2,
	["box"] = 3,
	["bomb"] = 4,
	["wall"] = 5,
	["free"] = 6,
	["danger"] = 7
}
X, Y = arg["x"], arg["y"]
AGGRO = arg["aggro"]
return launch_passive()
