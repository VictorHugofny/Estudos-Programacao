import prismaClient from "../../prisma";

interface OrderRequest{
    order_id: string;
}

class DetaildOrderService{
    async execute({order_id}: OrderRequest){
        console.log(order_id)
        const orders = await prismaClient.item.findMany({
            where:{
               order_id: order_id 
            },
            //incluido os dados das duas tabelas
            include:{
                product: true,
                order: true
            }
        })

        return orders
    }
}

export{DetaildOrderService}